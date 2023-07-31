package grayscale;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;
import javax.imageio.ImageIO;

/*
Codificação Luma em sistemas de vídeo
Artigo principal: luma (video)
Para imagens em espaços de cores como Y'UV e seus parentes, 
que são usados em sistemas de TV e vídeo em cores padrão 
como PAL, SECAM e NTSC, um componente de luma não linear (Y ') 
é calculado diretamente a partir de intensidades primárias 
comprimidas por gama. como uma soma ponderada que, 
embora não seja uma representação perfeita da luminância 
colorimétrica, pode ser calculada mais rapidamente sem a 
expansão e compressão gama usadas nos cálculos 
fotométricos / colorimétricos. Nos modelos Y'UV e Y'IQ 
usados por PAL e NTSC, o componente rec601 luma (Y ') 
é calculado como Y' = 0,299 * R '+ 0,587 * G' + 0,114 * B '
https://en.wikipedia.org/wiki/Grayscale
*/

public class Grayscale {
    
    //Cria um objeto do tipo imagem e variaveis para armazenar a altura e largura
    BufferedImage image;
    int width;
    int height;

    public Grayscale() {

        try {
            //Aloca o nome do arquivo para ser utilizado,
            File input = new File("test.jpg");
            //Obtem a imagem a ser manipulada
            image = ImageIO.read(input);
            //Obtem os tamanhos
            width = image.getWidth();
            height = image.getHeight();
            
            //Este loop, faz as operações pixel a pixel
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    //Cria um objeto de cor, para manipular as cores da imagem,
                    //Este objeto obtem a cor em forma rgb de cada ponto
                    //e faz a divisão.
                    Color c = new Color(image.getRGB(j, i));
                    
                    //Faz a multiplicação do pixel e suas cores pelas constantes
                    //de transformação de gama da imagem.
                    int red = (int) (c.getRed() * 0.299);
                    int green = (int) (c.getGreen() * 0.587);
                    int blue = (int) (c.getBlue() * 0.114);
                    
                    //Cria um novo objeto de cor para armazenar a nova cor
                    //Assim, como a formula já diz, faz a substituição das cores
                    //anteriormente manipuladas.
                    Color newColor = new Color( red + green + blue, 
                                                red + green + blue,
                                                red + green + blue);
                    
                    //Define o pixel na imagem, com as novas cores
                    image.setRGB(j, i, newColor.getRGB());
                }
            }
            
            //Aloca um objeto de local do arquivo.
            File ouptut = new File("grayscale.jpg");
            //Grava o objeto no disco
            ImageIO.write(image, "jpg", ouptut);

        } catch (Exception e) {
            System.out.print("Exception: " + e.toString());
        }
    }

    static public void main(String args[]) throws Exception {
        //Faz a instancia do objeto para ser disparada a função.
        Grayscale obj = new Grayscale();
    }
}
