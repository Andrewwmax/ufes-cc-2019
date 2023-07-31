package bilinearinterpolation;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.regex.Pattern;
import javax.swing.JOptionPane;

public class BilinearInterpolation {

    public static void main(String[] args) throws IOException {
        //Procução do menu
        boolean flag;
        do {
            String name = (String) JOptionPane.showInputDialog(null, "CG - Rotação", "Digite o Nome do Arquivo", JOptionPane.QUESTION_MESSAGE, null, null, "test.jpg");
            File im = new File(name);
            String angulo = (String) JOptionPane.showInputDialog(null, "CG - Rotação", "Digite o ÂNGULO", JOptionPane.QUESTION_MESSAGE, null, null, "45");
            BufferedImage image = ImageIO.read(im);
            BufferedImage image2 = rotation(image, Math.toRadians(Integer.parseInt(angulo)));
            String[] t = name.split (Pattern.quote ("."));
            ImageIO.write(image2, "png", new File(t[0] + "_" + angulo + ".png"));
            if (JOptionPane.showConfirmDialog(null, "Imagem Rotacionada com Sucesso! ! ! ! !\n\n\nDeseja Rotacionar uma nova Imagem??", "CG - Rotação", JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE) == JOptionPane.YES_NO_OPTION) {
                flag = true;
            } else {
                flag = false;
            }
        } while (flag != false);
    }

    private static BufferedImage rotation(BufferedImage self, double angulo) {
        //dimensoes da imagem
        int newWidth = (int) (self.getWidth() * 2);
        int newHeight = (int) (self.getHeight() * 2);
        int a = self.getWidth() / 2;
        int b = self.getHeight() / 2;
        BufferedImage result = new BufferedImage(newWidth, newHeight, self.getType());
        //centraliza a imagem na imagem de saida
        for (int i = 0; i < a * 2; i++) {
            for (int j = 0; j < b * 2; j++) {
                result.setRGB(i + a, j + b, self.getRGB(i, j));
            }
        }

        BufferedImage newImage = new BufferedImage(newWidth, newHeight, self.getType());
        System.err.println(self.getHeight() + ", " + self.getHeight());
        for (int x = a; x < result.getWidth() - a; x++) {
            for (int y = b; y < result.getHeight() - b; y++) {

//                float gx = (float) Math.abs(x * Math.cos(-angle) - y * Math.sin(-angle));
//                float gy = (float) Math.abs(x * Math.sin(-angle) + y * Math.cos(-angle));
                //aplica o calculo do pixel a ser rotacionado
                float gx = (float) Math.abs(x * Math.cos(-angulo) - y * Math.sin(-angulo) - self.getWidth() * Math.cos(-angulo) + self.getWidth() + self.getHeight() * Math.sin(-angulo));
                float gy = (float) Math.abs(y * Math.cos(-angulo) + x * Math.sin(-angulo) - self.getWidth() * Math.sin(-angulo) - self.getHeight() * Math.cos(-angulo) + self.getHeight());

                //System.err.println("(" + x + " = " + gx + ", " + y + " = " + gy + " )");
                //casting, e utiliza o valor futuramente
                int gxi = (int) gx;
                int gyi = (int) gy;
                int rgb = 0;
                int c00 = 0, c10 = 0, c01 = 0, c11 = 0;
//                if (x <  || x >= self.getWidth() - 1 || y < 0 || y >= self.getHeight() - 1) {
//                    c00 = self.getRGB(gxi, gyi);
//                    c10 = c00 = self.getRGB(gxi, gyi);
//                    c01 = c00 = self.getRGB(gxi, gyi);
//                    c11 = c00 = self.getRGB(gxi, gyi);
//                    System.err.println("------------------------------------->>>>>>>>>>>>>> pqp");
//                } else {
                //obtem o valor de cada pixel da imagem original
                c00 = result.getRGB(gxi, gyi);
                c10 = result.getRGB(gxi + 1, gyi);
                c01 = result.getRGB(gxi, gyi + 1);
                c11 = result.getRGB(gxi + 1, gyi + 1);
                //}
                for (int i = 0; i <= 2; ++i) {
                    //retira o canal de cor desejado, um a um para o calculo
                    float b00 = (c00 >> (i * 8)) & 0xFF;
                    float b10 = (c10 >> (i * 8)) & 0xFF;
                    float b01 = (c01 >> (i * 8)) & 0xFF;
                    float b11 = (c11 >> (i * 8)) & 0xFF;
                    //int ble = ((int) ((c00 + (c10 - c00) * gx - gxi) + ((c01 + (c11 - c01) * gx - gxi) - (c00 + (c10 - c00) * gx - gxi)) * gy - gyi)) << (8 * i);
                    //funcao que aplica o calculo do mais proximo
                    int ble = ((int) proxComp(b00, b10, b01, b11, gx - gxi, gy - gyi)) << (8 * i);
                    //comparativo entre o resultado, bit a bit, reconhecendo apenas maiores que 0.
                    rgb = rgb | ble;
                }
                //cria o pixel na nova imagem, atribuindo a cor do pixel
                newImage.setRGB(x, y, rgb);
            }
        }
//
//        int cX1 = (int) Math.abs(b * Math.cos(angle) - (result.getWidth() + a) * Math.sin(angle) - result.getWidth() * Math.cos(angle) + result.getWidth() + result.getHeight() * Math.sin(angle));
//        int cY1 = (int) Math.abs(a * Math.cos(angle) + b * Math.sin(angle) - result.getWidth() * Math.sin(angle) - result.getHeight() * Math.cos(angle) + result.getHeight());
//
//        //Calculo dos extremos da matriz, ultimo ponto a inferior direito
//        int cX2 = (int) Math.abs((result.getWidth() + a) * Math.cos(angle) - b * Math.sin(angle) - result.getWidth() * Math.cos(angle) + result.getWidth() + result.getHeight() * Math.sin(angle));
//        int cY2 = (int) Math.abs((result.getHeight() + b) * Math.cos(angle) + (result.getWidth() + a) * Math.sin(angle) - result.getWidth() * Math.sin(angle) - result.getHeight() * Math.cos(angle) + result.getHeight());
//
//        newImage = newImage.getSubimage(cX1, cY1, cX2 - cX1, cY2 - cY1)

        //faz o recorte da imagem, sob o tamanho da original
        newImage = newImage.getSubimage(a, b, self.getWidth(), self.getHeight());
        return newImage;
    }

    //Obtém o n-esimo byte de um int, que tem o valor de canal especifico
//    private static int get(int self, int i) {
//        return (self >> (i * 8)) & 0xFF;
//    }
//Aplica a formula do pixel mais proximo
    private static float prox(float s, float e, float t) {
        return s + (e - s) * t;
    }
//faz o calculo dos 3 pixels usando a formula do mais proximo

    private static float proxComp(final Float p00, float p10, float p01, float p11, float tx, float ty) {
        return prox(prox(p00, p10, tx), prox(p01, p11, tx), ty);
    }
}
