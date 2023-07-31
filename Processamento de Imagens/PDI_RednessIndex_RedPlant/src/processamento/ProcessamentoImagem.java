package processamento;

import java.awt.Color;
import java.awt.image.BufferedImage;

/**
 * @author André Couto
 */

public class ProcessamentoImagem {

	public static BufferedImage riRedPlant(BufferedImage imagem) {
		double max = -Double.MAX_VALUE;
		double min = Double.MAX_VALUE;
		double ri;

		for(int i = 0; i < imagem.getWidth(); i++) {
			for(int j = 0; j < imagem.getHeight(); j++) {
				Color c = new Color(imagem.getRGB(i, j));
				double r = new Double(c.getRed());
				double g = new Double(c.getGreen());
				
				ri = (double)(r - g) / (r + g);
				
				if (ri < min) min = ri;
				if (ri > max) max = ri;
			}
		}
		
		for(int i = 0; i < imagem.getWidth(); i++) {
			for(int j = 0; j < imagem.getHeight(); j++) {
				Color c = new Color(imagem.getRGB(i, j));
				double r = new Double(c.getRed());
				double g = new Double(c.getGreen());
				
				ri = (double)(r - g) / (r + g);

				if(((r + g) <= 0)){ 
					Color novo = new Color(0, 0, 0);
					imagem.setRGB(i, j, novo.getRGB());
				} else {
					double riNormalizado = 255 * ((ri - min) / (max - min));
					int riBW = (int) riNormalizado;

					Color novo = new Color(riBW, riBW, riBW);
					imagem.setRGB(i, j, novo.getRGB());
				}
			}
		}
		return imagem;
	}
                    /*
					// Calculo opcional para Normalização,
					// por se encaixar melhor em determinadas ocasiões

                    ri =  ri * 255;
					
                    if((ri) < 0){
					   Color newColor = new Color(0, 0, 0);
					   imagem.setRGB(i, j, newColor.getRGB());
					} else if(ri > 255){
					   Color newColor = new Color((int)(ri), (int)(ri), (int)(ri));
					   imagem.setRGB(i, j, newColor.getRGB());
					} else {
					   Color newColor = new Color((int) ri, (int) ri, (int) ri);
					   imagem.setRGB(i, j, newColor.getRGB());
					}
                    */
					
	
	public static BufferedImage OtsuBinarization(BufferedImage img) {
		
		BufferedImage res = new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
		// ROTINA de de Otsu TRADICIONAL

		//Armazenando o tamanho da imagem
		int Largura = img.getWidth();// Largura da imagem
		int Altura = img.getHeight();// Altura da imagem
		int col, lin, i, cinza;
		double totalPixel= (double) Largura * Altura;
		double [] proba = new double[256];
		int [] histogram = new int[256];
		int k, uiLimiar;
			   
		// inicializacao do Histograma
		for(i=0; i < 256; i++){
			histogram[i]= 0;
		}

		// calculo do Histograma  
		for( lin = 0; lin < Altura; lin++) {
			for( col = 0; col < Largura; col++) {
				Color x = new Color(img.getRGB(col,lin));
				cinza = (int)((x.getGreen() + x.getRed() + x.getBlue())/3);
				histogram[cinza]++;
			}
		}
			
		// Aloca as Matrizes
		double fSigmaBMax, fMiTotal;
		double [] fOmega = new double[256], fMi = new double[256] , fSigmaB = new double[256];

		//Passo 2: Calculo de probabilidades
		for (i = 0; i < 256; i++) {
			proba[i] = (double) ((histogram[i])/(double)(totalPixel));
			fOmega[i] = fMi[i] = 0.0;
		}

		for (k = 0; k < 256; k++){
			for (i = 0; i < k; i++){
				fOmega[k] += proba[i];
			}
		}

		for (k = 0; k < 256; k++){
			for (i = 0; i < k; i++){
				fMi[k] += (i + 1) * proba[i];
			}
		}
	  
		fMiTotal = fSigmaBMax = 0.0;  
		uiLimiar = 128; //inicialização do valor de limiar  de Otsu

		for (i = 0; i < 256; i++){
			fMiTotal += (i + 1) * proba[i];
		}

		if ((fOmega[0] * (1 - fOmega[0])) != 0.0){
			fSigmaBMax = (  (fMiTotal * fOmega[0] - fMi[0]) * (fMiTotal * fOmega[0] - fMi[0]) ) / (fOmega[0] * (1 - fOmega[0]));
			uiLimiar = 0;
		}

		for (k = 1; k < 256; k++){
			if ((fOmega[k] * (1 - fOmega[k])) != 0.0){
			   fSigmaB[k] = (  (fMiTotal * fOmega[k] - fMi[k]) * (fMiTotal * fOmega[k] - fMi[k]) ) / (fOmega[k] * (1 - fOmega[k]));

				if (fSigmaB[k] > fSigmaBMax){
					fSigmaBMax = fSigmaB[k];
					uiLimiar = ( int) k;
				}
			}
		}
		
		// valor de limiar  de Otsu modificado para poder pegar toda a regiao da mama 
		System.out.println(uiLimiar);
		
		//Cria a  imagem  binarizada 
		// Aloca a Matriz
		int [][] pBufferbinario = new int[Altura][Largura]; //Cria um PONTEIRO para a  imagem  binarizada 

		for( lin = 0; lin < Altura; lin++) {
			for( col = 0; col < Largura; col++) {
			Color x = new Color(img.getRGB(col,lin));
				cinza = (int)((x.getGreen() + x.getRed() + x.getBlue())/3); 
				if (cinza < uiLimiar){
					pBufferbinario[lin][col] = 1;
				} else {
					//255; mudado para fazer a multiplicacao img original * binária
					pBufferbinario[lin][col] = 0;
				}
			}
		}

		//Aqui Gera a  imagem binária 
		for( lin = 0; lin < Altura; lin++) {
			for( col = 0; col < Largura; col++){
				int atual = pBufferbinario[lin][col]* 255;
				Color novo = new Color(atual, atual, atual);
				res.setRGB(col,lin, novo.getRGB());
			}
		}
		return res;
	}	
}
