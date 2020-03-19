#include "stdafx.h"
#include "TGAWR.h"


CTGAWR::CTGAWR()
{
}


CTGAWR::~CTGAWR()
{
}

GLint CTGAWR::gltWriteTGA(const char* szFileName)
{
	/*
	FILE *pFile;		//ͷ�ļ�ָ��
	TGAHeader tgaHeader;//TGAͷ�ļ�
	unsigned long lImageSize;//ͼ��Ĵ�С�����ֽڱ�ʾ
	GLbyte* pBits = NULL; //ָ��λ��ָ��
	GLint iViewport[4];//�����ر�ʾ���ӿ�
	//GLenum  lastBuffer;
	GLint  lastBuffer;//���浱ǰ�Ķ�ȡ����������
	//��ȡ�ӿڴ�С
	glGetIntegerv(GL_VIEWPORT, iViewport);
	//ͼ��Ӧ�ö��targa�ļ��������ܰ�װ��
	lImageSize = iViewport[2] * 3 * iViewport[3];
	//����飬������ֲ������������򷵻�
	pBits = (GLbyte*)malloc(lImageSize);
	if (pBits == NULL)
		return 0;

	//����ɫ��������ȡ
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glPixelStorei(GL_PACK_ROW_LENGTH, 0);
	glPixelStorei(GL_PACK_SKIP_ROWS, 0);
	glPixelStorei(GL_PACK_SKIP_PIXELS, 0);

	//��ȡ��ǰ��ȡ���������ò����б���
	//�л���ǰ̨�����������ж�ȡ���������ָ���ȡ������״̬
	glGetIntegerv(GL_READ_BUFFER, &lastBuffer);
	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, iViewport[2], iViewport[3], GL_BGR, GL_UNSIGNED_BYTE, pBits);
	glReadBuffer(lastBuffer);
	//��ʼ��Targaͷ
	
	*/
	return 0;
}

bool CTGAWR::LoadTGA(TextureImage * texture, CString cfilename)
{
	
	
	
	if (!cfile.Open(cfilename, CFile::modeRead | CFile::typeBinary, NULL))
	{
		return false;
	}
	//else return true;
			// Open The TGA File  
	
	
	
	if (cfile == NULL)
	{                                
		return false;
	}
	//cfile.SeekToBegin();
	for (int i = 0; i < 12;i++)
	{
		cfile.Seek(i, CFile::begin);
		cfile.Read((tgaheader.Header + i), 1);

	}


	


	

	if (TGAHeaderCompare(uTGAcompare, tgaheader.Header))
	{
		//��ȡδѹ����TGA�ļ�
		LoadUncompressedTGA(texture);
	}
	//else if (TGAHeaderCompare(uTGAcompare, tgaheader.Header))
	{
		//��ȡδѹ����TGA�ļ�
	//	LoadCompressedTGA(texture);
	}
	//else
	{
	//	cfile.Close();
	//	return false;
	}

	
	cfile.Close();
	return true;                                       
}

//��ȡδѹ����TGA�ļ�
bool CTGAWR::LoadUncompressedTGA(TextureImage* texture)
{

	//���������3��������ͷ������LoadTGA�е�һ���������Ǽ򵥵Ĵ��ݡ�������������ǰһ�������е��ļ�ָ�룬�������û�ж�ʧ���ǵĿռ䡣
	//	���������������ٴ��ļ��ж�ȡ6���ֽڵ����ݣ����Ҵ洢��tga.header�С������ʧ���ˣ���������һЩ��������룬���ҷ���false��
	
		// ���Լ�����ȡ6���ֽڵ�����
	for (int i = 12; i < 18;i++)
	{
		cfile.Seek(i , CFile::begin);
		cfile.Read((tga.header + i - 12), 1);
	}
	

	//�����������˼���ͼ��ĸ߶ȡ���Ⱥ�BPP��ȫ����Ϣ������������ͱ��ؽṹ�ж����洢����

	texture->width = tga.header[1] * 256 + tga.header[0]; // ����߶�
	texture->height = tga.header[3] * 256 + tga.header[2]; // ������
	texture->bpp = tga.header[4];   // ����BPP
	tga.Width = texture->width;    // ����Width�����ؽṹ��ȥ
	tga.Height = texture->height;   // ����Height�����ؽṹ��ȥ
	tga.Bpp = texture->bpp;    // ����Bpp�����ؽṹ��ȥ

	//���ڣ�������Ҫȷ�ϸ߶ȺͿ������Ϊ1�����أ�����bpp��24��32�������Щֵ�е��κ�һ�����������ǵĽ��ޣ����ǽ���һ����ʾһ�����󣬹ر��ļ��������뿪�˺�����

		// ȷ�����е���Ϣ������Ч��
	if ((texture->width <= 0) || (texture->height <= 0) || ((texture->bpp != 24) && (texture->bpp != 32)))
	{
		//	...Error code here...
		return false;    // ���� False
	}

	//��������������ͼ������͡�24 bitͼ����GL_RGB��32 bit ͼ����GL_RGBA

	if (texture->bpp == 24)    // ��24 bitͼ����
	{
		texture->type = GL_RGB;   //����ǣ���������ΪGL_RGB
	}
	else      // �������24bit,�����32bit
	{
		texture->type = GL_RGBA;  //������������ΪGL_RGBA
	}

	//�������Ǽ���ÿ���ص��ֽ������ܹ���ͼ�����ݡ�

	tga.bytesPerPixel = (tga.Bpp / 8);  // ����BPP
										// ����洢ͼ��������ڴ�
	tga.imageSize = (tga.bytesPerPixel * tga.Width * tga.Height);

	//������ҪһЩ�ռ�ȥ�洢����ͼ�����ݣ�������ǽ�Ҫʹ��malloc������ȷ���ڴ�����
		//Ȼ������ȷ���ڴ��Ѿ����䣬����������NULL����������˴��������д�������롣


		// �����ڴ�
	texture->imageData = (GLubyte *)malloc(tga.imageSize);
	if (texture->imageData == NULL)   // ȷ���Ѿ�����ɹ�
	{
		//...Error code here...
		return false;    // ȷ���Ѿ�����ɹ�
	}

	//�������ǳ��Զ�ȡ���е�ͼ�����ݡ�������ܣ����ǽ��ٴδ�����������롣

		// ���Զ�ȡ����ͼ������
	

	for (int i = 18; i < tga.imageSize+18;i++)
	{
		cfile.Seek(i, CFile::begin);
		cfile.Read((texture->imageData + i-18), 1);

	}


	//TGA�ļ�����OpenGL����˳��ķ�ʽ�洢ͼ��������Ǳ��뽫��ʽ��BGR��RGB��Ϊ�˴ﵽ��һ�㣬���ǽ���ÿ�����صĵ�һ���͵������ֽڵ����ݡ�
	//	Steve Thomas���䣺���Ѿ���д������΢�����ٶ�ȡTGA�ļ��Ĵ��롣���漰������3�������Ʋ�����BGRת����RGB�ķ�����
	//	Ȼ�����ǹر��ļ������ҳɹ��˳�������


		//  ��ʼѭ��
	for (GLuint cswap = 0; cswap < (int)tga.imageSize; cswap += tga.bytesPerPixel)
	{
		// ��һ�ֽ� XOR�����ֽ�XOR ��һ�ֽ� XOR �����ֽ�
		texture->imageData[cswap] ^= texture->imageData[cswap + 2] ^=
			texture->imageData[cswap] ^= texture->imageData[cswap + 2];
	}
	//cfile.Close();     // �ر��ļ�
	return true;     // ���سɹ�
}

//�����Ƕ�ȡδѹ����TGA�ļ��ķ�������ȡRLEѹ�����ļ��Ĳ�����΢��һ�㡣������ƽʱһ����ȡ�ļ�ͷ�����ռ��߶ȣ���ȣ�ɫ����ȣ���Ͷ�ȡδѹ���汾��һ�µġ�

bool CTGAWR::LoadCompressedTGA(TextureImage* texture)
{
	//���������3��������ͷ������LoadTGA�е�һ���������Ǽ򵥵Ĵ��ݡ�������������ǰһ�������е��ļ�ָ�룬�������û�ж�ʧ���ǵĿռ䡣
	//	���������������ٴ��ļ��ж�ȡ6���ֽڵ����ݣ����Ҵ洢��tga.header�С������ʧ���ˣ���������һЩ��������룬���ҷ���false��

	// ���Լ�����ȡ6���ֽڵ�����
	for (int i = 12; i < 18;i++)
	{
		cfile.Seek(i, CFile::begin);
		cfile.Read((tga.header + i - 12), 1);
	}


	//�����������˼���ͼ��ĸ߶ȡ���Ⱥ�BPP��ȫ����Ϣ������������ͱ��ؽṹ�ж����洢����

	texture->width = tga.header[1] * 256 + tga.header[0]; // ����߶�
	texture->height = tga.header[3] * 256 + tga.header[2]; // ������
	texture->bpp = tga.header[4];   // ����BPP
	tga.Width = texture->width;    // ����Width�����ؽṹ��ȥ
	tga.Height = texture->height;   // ����Height�����ؽṹ��ȥ
	tga.Bpp = texture->bpp;    // ����Bpp�����ؽṹ��ȥ

							   //���ڣ�������Ҫȷ�ϸ߶ȺͿ������Ϊ1�����أ�����bpp��24��32�������Щֵ�е��κ�һ�����������ǵĽ��ޣ����ǽ���һ����ʾһ�����󣬹ر��ļ��������뿪�˺�����

							   // ȷ�����е���Ϣ������Ч��
	if ((texture->width <= 0) || (texture->height <= 0) || ((texture->bpp != 24) && (texture->bpp != 32)))
	{
		//	...Error code here...
		return false;    // ���� False
	}

	//��������������ͼ������͡�24 bitͼ����GL_RGB��32 bit ͼ����GL_RGBA

	if (texture->bpp == 24)    // ��24 bitͼ����
	{
		texture->type = GL_RGB;   //����ǣ���������ΪGL_RGB
	}
	else      // �������24bit,�����32bit
	{
		texture->type = GL_RGBA;  //������������ΪGL_RGBA
	}

	//�������Ǽ���ÿ���ص��ֽ������ܹ���ͼ�����ݡ�

	tga.bytesPerPixel = (tga.Bpp / 8);  // ����BPP
										// ����洢ͼ��������ڴ�
	tga.imageSize = (tga.bytesPerPixel * tga.Width * tga.Height);

	//������ҪһЩ�ռ�ȥ�洢����ͼ�����ݣ�������ǽ�Ҫʹ��malloc������ȷ���ڴ�����
	//Ȼ������ȷ���ڴ��Ѿ����䣬����������NULL����������˴��������д�������롣

	//����������Ҫ����洢ͼ������Ŀռ䣬����Ϊ���ǽ�ѹ��֮��׼���ģ����ǽ�ʹ��malloc������ڴ����ʧ�ܣ����д�������룬���ҷ���false��

	// ����洢ͼ��������ڴ�ռ�
	texture->imageData = (GLubyte *)malloc(tga.imageSize);
	if (texture->imageData == NULL)   // ������ܷ����ڴ�
	{
		//...Error code here...
		return false;    // ���� False
	}

	//��һ��������Ҫ�������ͼ��������������ǽ����洢�ڱ�����pixelcount���С�
	//����Ҳ��Ҫ�洢��ǰ���������أ��Լ���������д���ͼ�����ݵ��ֽڣ������������д�����ľ����ݡ�

	//���ǽ�Ҫ�����㹻���ڴ����洢һ�����ء�


	GLuint pixelcount = tga.Height * tga.Width; // ͼ���е�������
	GLuint currentpixel = 0;  // ��ǰ���ڶ�ȡ������
	GLuint currentbyte = 0;   // ��ǰ������ͼ����д�������
							  // һ�����صĴ洢�ռ�
	GLubyte * colorbuffer = (GLubyte *)malloc(tga.bytesPerPixel);

	//���������ǽ�Ҫ����һ����ѭ����
	//�����ǽ����ֽ�Ϊ����ɹ���Ŀ顣
	//������������һ���������洢���顱ͷ����ͷָʾ�������Ķ���RLE����RAW�����ĳ����Ƕ��١�
	//���һ�ֽ�ͷС�ڵ���127��������һ��RAWͷ��ͷ��ֵ����ɫ�����Ǹ����������Ǵ�������ͷ�ֽ�֮ǰ�������ȶ�ȡ�����ҿ������ڴ��С�
	//�������ǽ����ǵõ���ֵ��1��Ȼ���ȡ�������ز��ҽ����ǿ�����ImageData�У��������Ǵ���δѹ����ͼ��һ�������ͷ����127��
	//��ô������һ������ֵ���Ҫ�ظ��Ĵ�����Ҫ��ȡʵ���ظ������������ǽ�����ȥ127�Գ�ȥ1bit�ĵ�ͷ��ʾ����
	//Ȼ�����Ƕ�ȡ��һ�����ز����������������������������ڴ��С�


	do      // ��ʼѭ��
	{
		GLubyte chunkheader = 0;    // �洢Id��ֵ�ı���
		
			for (int i = 12; i < sizeof(GLubyte);i++)
			{
				cfile.Seek(i, CFile::begin);
				cfile.Read((&chunkheader + i-12), 1);

			}
			//return false;    // If It Fails, Return False
		

		//���������ǽ�Ҫ�������Ƿ���RAWͷ������ǣ�������Ҫ���˱�����ֵ��1�Ի�ȡ����ͷ֮�������������

		if (chunkheader < 128)    // �����RAW��
		{
			chunkheader++;    // ����ֵ��1�Ի�ȡRAW���ص�����

		//	���ǿ�����һ��ѭ����ȡ���е���ɫ��Ϣ��������ѭ����ͷ��ָ���Ĵ���������ÿ��ѭ����ȡ�ʹ洢һ�����ء�
		//		���ȣ����Ƕ�ȡ�������������ݡ��������ص����ݽ����洢��colorbuffer�����С�Ȼ�����ǽ�������Ƿ�ΪRAWͷ������ǣ�������Ҫ���һ��������֮���Ի�ȡͷ֮�������������


				// ��ʼ���ض�ȡѭ��
			for (short counter = 0; counter < chunkheader; counter++)
			{
				// ���Զ�ȡһ������
				//if (fread(colorbuffer, 1, tga.bytesPerPixel, fTGA) != tga.bytesPerPixel)
				{
					//				...Error code...
					return false;   // ���ʧ�ܣ�����false
				}

				//			����ѭ���е���һ����Ҫ��ȡ�洢��colorbuffer�е���ɫֵ���ҽ���д���Ժ�Ҫʹ�õ�imageData�����С�����������У����ݸ�ʽ������BGR��תΪRGB����BGRAת��ΪRGBA���������ȡ����ÿ���صı����������������������������ӵ�ǰ���ֽں͵�ǰ�����ؼ�������

				texture->imageData[currentbyte] = colorbuffer[2];  // д��R���ֽ�
				texture->imageData[currentbyte + 1] = colorbuffer[1]; //д��G���ֽ�
				texture->imageData[currentbyte + 2] = colorbuffer[0]; // д��B���ֽ�
				if (tga.bytesPerPixel == 4)     // �����32λͼ��...
				{
					texture->imageData[currentbyte + 3] = colorbuffer[3]; // д��A���ֽ�
				}
				// ����ÿ���ص��ֽ��������ֽڼ�����
				currentbyte += tga.bytesPerPixel;
				currentpixel++;     // ���ؼ�������1

		//		��һ�δ�������RLE�εġ��顱ͷ���������ǽ�chunkheader��ȥ127���õ���ȡ��һ����ɫ�ظ��Ĵ�����
			}
		}
		else      // �����RLEͷ
		{
			chunkheader -= 127;   //  ��ȥ127���ID Bit��Rid
		}
		//		Ȼ�����ǳ��Զ�ȡ��һ����ɫֵ��

					// ��ȡ��һ������
		//if (fread(colorbuffer, 1, tga.bytesPerPixel, fTGA) != tga.bytesPerPixel)
		{
			//				...Error code...
			return false;    // ���ʧ�ܣ�����false
		}

		//�����������ǿ�ʼѭ���������Ƕ�ζ����ڴ��е����أ�����RLEͷ�е�ֵ�涨��
		//	Ȼ�����ǽ���ɫֵ������ͼ�������У�Ԥ����R��B��ֵ������
		//	����������ӵ�ǰ���ֽ�������ǰ���أ����������ٴ�д��ֵʱ���Դ�����ȷ��λ�á�


			// ��ʼѭ��
		for (short counter = 0; counter < chunkheader; counter++)
		{
			// ������R���ֽ�
			texture->imageData[currentbyte] = colorbuffer[2];
			// ������G���ֽ�
			texture->imageData[currentbyte + 1] = colorbuffer[1];
			// ������B���ֽ�
			texture->imageData[currentbyte + 2] = colorbuffer[0];
			if (tga.bytesPerPixel == 4)  // �����32λͼ��
			{
				// ������A���ֽ�
				texture->imageData[currentbyte + 3] = colorbuffer[3];
			}
			currentbyte += tga.bytesPerPixel; // �����ֽڼ�����
			currentpixel++;   // �����ֽڼ�����

	//		ֻҪ��ʣ������Ҫ��ȡ�����ǽ��������ѭ����
	//			������ǹر��ļ������سɹ���
		}

	} while (currentpixel < pixelcount); // �Ƿ��и��������Ҫ��ȡ����ʼѭ��ֱ�����
	//fclose(fTGA);   // �ر��ļ�
	return true;   // ���سɹ�
}

bool CTGAWR::TGAHeaderCompare(GLubyte* TGACompare, GLubyte* HeaderCompare)
{
	for (int i = 0;i < 12;i++)
	{
		if (!(*(TGACompare + i) == *(HeaderCompare + i)))
			return false;
	}
	return true;
}




void CTGAWR::zTexture2D(TextureImage* texture, int p)
{


	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


	

	/*��������*/
	
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture[p].width, texture[p].height, 0, texture[p].type, GL_UNSIGNED_BYTE, texture[p].imageData);
	
	//��������
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	

	//˵��������ͼ��ʽ
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	/*����������ͼ*/
	//glEnable(GL_TEXTURE_2D);
	
	//glShadeModel(GL_SMOOTH);
	/*����������������弸������*/
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f);glVertex3f(-1.0f, -1.0f, 0.0f);
	//glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
	//glTexCoord2f(1.0f, 1.0f);glVertex3f(1.0f, 1.0f, 0.0f);
	//glTexCoord2f(1.0f, 0.0f);glVertex3f(1.0f, -1.0f, 0.0f);
//	glEnd();

	//glDisable(GL_TEXTURE_2D);
	
}


