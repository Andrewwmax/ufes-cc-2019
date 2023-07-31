package rotationfinal;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class RotationFinal {

    /* Obtém o 'n' byte de um inteiro de 4 bytes 
    passa n * 8 bits, assim selecionando somente a cor desejada*/
    private static int getR_G_B(int pixel, int n) {
    	return (pixel >> (n * 8)) & 0xFF;
    }
    /*Faz a aplicacao da formula de interpolacao, que usa os pixels
    proximos para obter a "importancia" de cada um no pixel central*/
    private static float subInterpolacao(float s, float e, float t) {
    	return s + (e - s) * t;
    }
    /*Faz a chamada do calculo de interpolacao, recursivamente, para
    obter a cor do pixel atual*/
    private static float interpolacao(final Float c00, float c10, float c01, float c11, float tx, float ty) {
    	return subInterpolacao(subInterpolacao(c00, c10, tx), subInterpolacao(c01, c11, tx), ty);
    }
	
	/*  Metodo create, faz toda a manipulação da imagem,
        Recebe a imagem, e utiliza as informações para executar a rotação,
        sobre a formula (i * Math.cos(angle) - j * Math.sin(angle)
                        (j * Math.cos(angle) + i * Math.sin(angle)
    */
    private static BufferedImage rorate(BufferedImage self, double angle) {
        //Armazena os tamanhos da imagem, largura e altura, e suas metades
		//A imagem com o dobro do tamanho para previnir erros de Falhas de segmentação
    	int newWidth = (int) (self.getWidth() * 2);
    	int newHeight = (int) (self.getHeight() * 2);
    	int a = self.getWidth() / 2;
    	int b = self.getHeight() / 2;
    	BufferedImage result = new BufferedImage(newWidth, newHeight, self.getType());

		//Translate to center
        //Faz a copia da imagem original para o centro da nova imagem a ser rotacionada
    	for (int i = 0; i < a * 2; i++) {
    		for (int j = 0; j < b * 2; j++) {
    			result.setRGB(i + a, j + b, self.getRGB(i, j));
    		}
    	}
    	//Nova imagem para o resultado final
    	BufferedImage newImage = new BufferedImage(newWidth, newHeight, self.getType());
    	for (int x = a; x < result.getWidth() - a; x++) {
    		for (int y = b; y < result.getHeight() - b; y++) {
    			//Onde cada posição (i,j), recebe um calculo para modifica-lá
                //Então um novo neww (new Width),
                //Então um novo newh (new height),
                //Estes são utilizados para definir o novo local
                //O absoluto faz com que o calculo fique com menos erros de pontos negativos
                //então temos a utilização do seno, cosseno e a soma de extremos 
                //para a rotação ser realizada no centro
    			float gx = (float) Math.abs(x * Math.cos(angle) - y * Math.sin(angle) - self.getWidth() * Math.cos(angle) + self.getWidth() + self.getHeight() * Math.sin(angle));
    			float gy = (float) Math.abs(y * Math.cos(angle) + x * Math.sin(angle) - self.getWidth() * Math.sin(angle) - self.getHeight() * Math.cos(angle) + self.getHeight());
    			//conversao de float para int, armazenando a diferenca para uso futuro
    			int gxi = (int) gx;
    			int gyi = (int) gy;
    			//criam se os valores dos pixels laterais, para o calculo de cada um
    			//fazendo o calculo de interpolacao entre cada cor
    			//com o detalhe de que se a variavel "ble" for menor que 0,
    			//ira assumir 0 como valor
    			int rgb = 0;
    			int c00 = 0, c10 = 0, c01 = 0, c11 = 0;
    			c00 = result.getRGB(gxi, gyi);
    			c10 = result.getRGB(gxi + 1, gyi);
    			c01 = result.getRGB(gxi, gyi + 1);
    			c11 = result.getRGB(gxi + 1, gyi + 1);
    			for (int i = 0; i <= 2; ++i) {
    				float b00 = getR_G_B(c00, i);
    				float b10 = getR_G_B(c10, i);
    				float b01 = getR_G_B(c01, i);
    				float b11 = getR_G_B(c11, i);
    				int ble = ((int) interpolacao(b00, b10, b01, b11, gx - gxi, gy - gyi)) << (8 * i);
    				rgb = rgb | ble;
    			}
    			//Então definimos o novo ponto, e sua cor, aparir do primeiro 
                //resultado copiado no centro
    			newImage.setRGB(x, y, rgb);
    		}
    	}
    	newImage = newImage.getSubimage(a, b, self.getWidth(), self.getHeight());
    	return newImage;
    }

    public static void main(String[] args) throws IOException {
        //Caminho da imagem
        //Instanciar a imagem, Carrega-la para a memória
		//Instanciar os objetos do tipo imagem para receberem a imagem processada,
        //cada um com suas propriedades de angulo e a imagem original
		BufferedImage image = ImageIO.read(new File("test.jpg"));    	
    	BufferedImage image2 = rorate(image, Math.toRadians(-15));
	    //Criar o arquivo de saida, um para cada imagem, gravando os objetos. 

    	ImageIO.write(image2, "png", new File("saidaR.png"));
    }
}
