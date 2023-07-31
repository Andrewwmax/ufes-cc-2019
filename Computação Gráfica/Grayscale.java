package grayscale;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;
import javax.imageio.ImageIO;

/*
Codifica��o Luma em sistemas de v�deo
Artigo principal: luma (video)
Para imagens em espa�os de cores como Y'UV e seus parentes, 
que s�o usados em sistemas de TV e v�deo em cores padr�o 
como PAL, SECAM e NTSC, um componente de luma n�o linear (Y ') 
� calculado diretamente a partir de intensidades prim�rias 
comprimidas por gama. como uma soma ponderada que, 
embora n�o seja uma representa��o perfeita da lumin�ncia 
colorim�trica, pode ser calculada mais rapidamente sem a 
expans�o e compress�o gama usadas nos c�lculos 
fotom�tricos / colorim�tricos. Nos modelos Y'UV e Y'IQ 
usados por PAL e NTSC, o componente rec601 luma (Y ') 
� calculado como Y' = 0,299 * R '+ 0,587 * G' + 0,114 * B '
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
            
            //Este loop, faz as opera��es pixel a pixel
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    //Cria um objeto de cor, para manipular as cores da imagem,
                    //Este objeto obtem a cor em forma rgb de cada ponto
                    //e faz a divis�o.
                    Color c = new Color(image.getRGB(j, i));
                    
                    //Faz a multiplica��o do pixel e suas cores pelas constantes
                    //de transforma��o de gama da imagem.
                    int red = (int) (c.getRed() * 0.299);
                    int green = (int) (c.getGreen() * 0.587);
                    int blue = (int) (c.getBlue() * 0.114);
                    
                    //Cria um novo objeto de cor para armazenar a nova cor
                    //Assim, como a formula j� diz, faz a substitui��o das cores
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
        //Faz a instancia do objeto para ser disparada a fun��o.
        Grayscale obj = new Grayscale();
    }
}
