package espelhov;

import java.io.File;
import java.io.IOException;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class EspelhoV {

    public static void main(String args[]) throws IOException {
		//imagem de origem
        BufferedImage simg = null;
        File f;
		//ler o arquivo da imagem origianl
        try {
            f = new File("test.jpg");
            simg = ImageIO.read(f);
        } catch (IOException e) {
            System.err.println("Error: " + e);
        }
        //pega a altura da imagem
        int width = simg.getWidth();
        //pega a largura da imagem
        int height = simg.getHeight();
        //imagem que recebera o resultado
        BufferedImage mimg = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
        //calculo pixel a pixel da nova posicao de cada um
        for (int x = 0; x < width; x++) {
            for (int pixelOriginal = 0, pixelDestino = height - 1; pixelOriginal < height; pixelOriginal++, pixelDestino--) {
            	//Percorrendo a matriz, pega o valor do pixel e faz a inversao no plano, para as coordenadas na nova imagem
                int p = simg.getRGB(x, pixelOriginal);
                mimg.setRGB(x, pixelDestino, p);
            }
        }
        //salva
        try {
            f = new File("saidaVertical.png");
            ImageIO.write(mimg, "png", f);
        } catch (IOException e) {
            System.err.println("Error: " + e);
        }
    }
}
