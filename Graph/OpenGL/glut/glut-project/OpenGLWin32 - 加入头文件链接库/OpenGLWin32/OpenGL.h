
class OpenGL  
{	public:	OpenGL();
	virtual ~OpenGL();
	public:

	HDC		hDC;		// GDI�豸������
	HGLRC	hRC;		// ������ɫ������
	BOOL	SetupPixelFormat(HDC hDC);
	void	init(int Width, int Height);
	void	Render();
	void	CleanUp();

};


