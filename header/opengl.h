#ifndef OPENGL
#define OPENGL

#pragma region OpenGL structures

struct GLFWvidmode {
	int width;
	int height;
	int redBits;
	int greenBits;
	int blueBits;
	int refreshRate;
};

struct GLFWgammaramp {
	unsigned short* red;
	unsigned short* green;
	unsigned short* blue;
	unsigned short size;
};

struct GLFWimage {
	int width;
	int height;
	unsigned char* pixels;
};

struct GLFWgamepadstate {
	unsigned char buttons[15];
	float axes[6];
};

struct GLFWwindow;
struct GLFWmonitor;
struct GLFWcursor;

struct VkInstance;
struct VkPhysicalDevice;
struct VkAllocationCallbacks;
struct VkSurfaceKHR;
struct VkResult;

#pragma endregion

#pragma region OpenGL callback prototypes
typedef void (*GLFWglproc)                   (void);
typedef void (*GLFWvkproc)                   (void);
typedef void (*GLFWerrorfun)                 (int error_code, const char* description);
typedef void (*GLFWwindowposfun)             (GLFWwindow* window, int xpos, int ypos);
typedef void (*GLFWwindowsizefun)            (GLFWwindow* window, int width, int height);
typedef void (*GLFWwindowclosefun)           (GLFWwindow* window);
typedef void (*GLFWwidowrefreshfun)          (GLFWwindow* window);
typedef void (*GLFWwindowfocusfun)           (GLFWwindow* window, int focused);
typedef void (*GLFWwindowiconifyfun)         (GLFWwindow* window, int iconified);
typedef void (*GLFWwindowmaximizefun)        (GLFWwindow* window, int maximized);
typedef void (*GLFWframebuffersizefun)       (GLFWwindow* window, int width, int height);
typedef void (*GLFWwindowcontentscalefun)    (GLFWwindow* window, float xscale, float yscale);
typedef void (*GLFWmousebuttonfun)           (GLFWwindow* window, int button, int action, int mods);
typedef void (*GLFWcursorposfun)             (GLFWwindow* window, double xpos, double ypos);
typedef void (*GLFWcursorenterfun)           (GLFWwindow* window, int entered);
typedef void (*GLFWscrollfun)                (GLFWwindow* window, double xoffset, double yoffset);
typedef void (*GLFWkeyfun)                   (GLFWwindow* window, int key, int scancode, int action, int mods);
typedef void (*GLFWcharfun)                  (GLFWwindow* window, unsigned int codepoint);
typedef void (*GLFWcharmodsfun)              (GLFWwindow* window, unsigned int codepoint, int mods);
typedef void (*GLFWdropfun)                  (GLFWwindow* window, int path_count, const char* paths[]);
typedef void (*GLFWmonitorfun)               (GLFWmonitor* monitor, int event);
typedef void (*GLFWjoystickfun)              (int joystick_id, int event);

#pragma endregion

#pragma region OpenGL API functions

int glfwInit(void);
void glfwTerminate(void);

void glfwInitHint(int hint, int value);

void glfwGetVersion(int* major, int* minor, int* revisions);
const char* glfwGetVersionString(void);

int glfwGetError(const char** description);

GLFWmonitor** glfwGetMonitors(int* count);
GLFWmonitor* glfwGetPrimaryMonitor(void);
void glfwGetMonitorPos(GLFWmonitor* monitor, int* xpos, int* ypos);
void glfwGetMonitorWorkArea(GLFWmonitor* monitor, int* xpos, int* ypos, int* width, int* height);
void glfwGetMonitorPhysicalSize(GLFWmonitor* monitor, int* widthMM, int* heightMM);
void glfwGetMonitorContentScale(GLFWmonitor* monitor, float* xscale, float* yscale);
const char* glfwGetMonitorName(GLFWmonitor* monitor);

GLFWmonitor* glfwGetWindowMonitor(GLFWwindow* window);
void glfwSetWindowMonitor(GLFWwindow* window, GLFWmonitor* monitor, int xpos, int ypos, int width, int height, int refreshRate);

void glfwSetMonitorUserPointer(GLFWmonitor* monitor, void* pointer);
void* glfwGetMonitorUserPointer(GLFWmonitor* monitor);

const GLFWvidmode* glfwGetVideoModes(GLFWmonitor* monitor, int* count);
const GLFWvidmode* glfwGetVideoMode(GLFWmonitor* monitor);

void glfwSetGamma(GLFWmonitor* monitor, float gamma);

const GLFWgammaramp* glfwGetGammaRamp(GLFWmonitor* monitor);
void glfwSetGammaRamp(GLFWmonitor* monitor, const GLFWgammaramp* ramp);

void glfwGetDefaultWindowHints(void);
void glfwWindowHint(int hint, int value);
void glfwWindowHintString(int hint, const char* value);

GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
void glfwDestroyWindow(GLFWwindow* window);

int glfwWindowShuoldClose(GLFWwindow* window);
void glfwSetWindowShuoldClose(GLFWwindow* window, int value);

void glfwSetWindowTitle(GLFWwindow* window, cosnt char* title);
void glfwSetWindowIcon(GLFWwindow* window, int count, const GLFWimage* image);

void glfwGetWindowPos(GLFWwindow* window, int* xpos, int* ypos);
void glfwSetWindowPos(GLFWwindow* window, int xpos, int ypos);

void glfwGetWindowSize(GLFWwindow* wondow, int* width, int* height);
void glfwSetWindowSizeLimits(GLFWwindow* window, int minwidth, int minheight, int maxwidth, int maxheight);

void glfwSetWindowAspectRatio(GLFWwindow* window, int numer, int denom);
void glfwSetWindowSize(GLFWwindow* window, int width, int height);
void glfwGetFramebufferSize(GLFWwindow* window, int* width, int* height);
void glfwGetWindowFrameSize(GLFWwindow* window, int* left, int* top, int* right, int* bottom);
void glfwGetWindowContextScale(GLFWwindow* window, float* xscale, float* yscale);
float glfwGetWindowOpacity(GLFWwindow* window);

void glfwSetWindowOpacity(GLFWwindow* wiondow, float opacity);
void glfwIconifyWindow(GLFWwindow* window);
void glfwRestoreWindow(GLFWwindow* window);
void glfwMaximizeWindow(GLFWwindow* window);
void glfwShowWindow(GLFWwindow* window);
void glfwHideWindow(GLFWwindow* window);
void glfwFocusWindow(GLFWwindow* window);
void glfwRequestWindowAttention(GLFWwindow* window);

int glfwGetWindowAttrib(GLFWwindow* window, int attrib);
void glfwSetWindowAttrib(GLFWwindow* window, int attrib, int value);

void glfwSetWindowUserPointer(GLFWwindow* window, void* pointer);
void* glfwGetWindowUserPointer(GLFWwindow* window);

GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun callback);
GLFWmonitorfun glfwSetMonitorCallback(GLFWmonitorfun callback);

GLFWwindowposfun glfwSetWindowPosCallback(GLFWwindow* window, GLFWwindowposfun callback);
GLFWwindowsizefun glfwSetWindowSieCallback(GLFWwindow* window, GLFWwindowsizefun callback);
GLFWwindowclosefun glfwSetWindowCloseCallback(GLFWwindow* window, GLFWwindowclosefun callback);
GLFWwindowfocusfun glfwSetWindowFocusCallback(GLFWwindow* window, GLFWwindowfocusfun callback);
GLFWwidowrefreshfun glfwSetWindowRefrechCallback(GLFWwindow* window, GLFWwidowrefreshfun callback);
GLFWwindowiconifyfun glfwSetWindowIconifyCallback(GLFWwindow* window, GLFWwindowiconifyfun callback);
GLFWwindowmaximizefun glfwSetWindowMaximizeCallback(GLFWwindow* window, GLFWwindowmaximizefun callback);
GLFWframebuffersizefun glfwSetFramebufferSizeCallback(GLFWwindow* window, GLFWframebuffersizefun callback);
GLFWwindowcontentscalefun glfwSetWindowContentScaleCallback(GLFWwindow* window, GLFWwindowcontentscalefun callback);

void glfwPollEvents(void);
void glfwWaitEvents(void);
void glfwWaitEventsTimeout(double timeout);
void glfwPostEmptyEvent(void);

int glfwGetInputMode(GLFWwindow* window, int mode);
void glfwSetInputMode(GLFWwindow* window, int mode, int value);

int glfwRawMouseMotionSupported(void);

const char* glfwGetKeyName(int key, int scancode);
int glfwGetKeyScancode(int key);
int glfwGetKey(GLFWwindow* window, int key);

int glfwGetMouseButton(GLFWwindow* window, int button);
void glfwGetCursorPos(GLFWwindow* window, double* xpos, double ypos);
void glfSetCursorPos(GLFWwindow* window, double xpos, double ypos);

GLFWcursor* glfwCreateStandardCursor(int shape);
void glfwDestroyCursor(GLFWcursor* cursor);
void glfwSetCursor(GLFWwindow* window, GLFWcursor* cursor);

GLFWkeyfun glfwSetKeyCallback(GLFWwindow* window, GLFWkeyfun callback);
GLFWcharfun glfwSetCharCallback(GLFWwindow* window, GLFWcharfun callback);
GLFWcharmodsfun glfwSeyCharModsCallback(GLFWwindow* window, GLFWcharmodsfun callback);
GLFWmousebuttonfun glfwSetMouseButtonCallback(GLFWwindow* window, GLFWmousebuttonfun callback);
GLFWcursorposfun glfwSetCursorPosCallback(GLFWwindow* window, GLFWcursorposfun callback);
GLFWjoystickfun glfwSetJoystickCallback(GLFWjoystickfun callback);
GLFWcursorenterfun glfwSetCursorEntarCallback(GLFWwindow* window, GLFWcursorenterfun callback);
GLFWscrollfun glfwSetScrollCallback(GLFWwindow* window, GLFWscrollfun callback);
GLFWdropfun glfwDropCallback(GLFWwindow* window, GLFWdropfun callback);

int glfwJoystickPresent(int joystick_id);
const float* glfwGetJoystickAxes(int joystick_id, int* count);
const unsigned char* glfwGetJoystickButtons(int joystick_id, int* count);
const unsigned char* glfwGetJoystickHats(int joystick_id, int* count);
const char* glfwGetJoystickName(int joystick_id);
const char* glfwGetJoystickGUID(int joystick_id);

void glfwSetJoystickUserPointer(int joystick_id, void* pointer);
void* glfwGetJoystickUserPointer(int joystick_id);

int glfwJoystickIsGamepad(int joystick_id);

int glfwUpdateGamepadMappings(const char* string);
const char* glfwGetGamepadName(int joystick_id);
int glfwGetGamepadState(int joystick_id, GLFWgamepadstate* state);

void glfwSetClipboardString(GLFWwindow* window, const char* string);
const char* glfwGetClipboardString(GLFWwindow* window);

double glfwGetTime(void);
void glfwSetTime(double time);

unsigned long long glfwGetTimerValue(void);
unsigned long long glfwGetTimerFrequency(void);

void glfwMakeContextCurrent(GLFWwindow* window);
GLFWwindow* glfwGetCurrentContext(void);

void glfwSwapBuffers(GLFWwindow* window);
void glfwSwapInterval(int interval);

int glfwExtensionSupported(const char* extension);
GLFWglproc glfwGetProcAddress(const char* procname);

int glfwVulkanSupported(void);
const char** glfwGetRequiredInstanceExtensions(unsigned int* count);

GLFWvkproc glfwGetInstanceProcAddress(VkInstance instance, const char* procname);
int glfwGetPhysicalDevicePresentationSupport(VkInstance instance, VkPhysicalDevice device, unsigned int queuefamily);
VkResult glfwCreateWindowSurface(VkInstance instance, GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);

#pragma endregion

#pragma region OpenGL main functions

typedef unsigned int GLenum, GLbitfield;
typedef unsigned short GLushort;
typedef unsigned __int8 GLubyte;

typedef int GLsizei;
typedef __int8 GLbyte;

#ifndef GL_VERSION_1_0
// 1946 - 2267 (18:44)

extern void glCullFace(GLenum mode);
extern void glFrontFace(GLenum mode);
extern void glHint(GLenum target, GLenum mode);
extern void glLineWidth(float width);
extern void glPointSize(float size);
extern void glPolygonMode(float face, GLenum mode);
extern void glScissor(Gint x, int y, GLsizei width, GLsizei height);

extern void glTexParameterf(GLenum target, GLenum pname, float param);
extern void glTexParameterfv(GLenum target, GLenum pname, const float* params);
extern void glTexParameteri(GLenum target, GLenum pname, int param);
extern void glTexParameteriv(GLenum target, GLenum pname, const int* params);

extern void glTexImage1D(GLenum target, int level, int internalFormat, GLsizei width, int border, GLenum format, GLenum type, const void* pixels);
extern void glTexImage2D(GLenum target, int level, int internalFormat, GLsizei width, GLsizei height, int border, GLenum format, GLenum type, const void* pixels);

extern void glDrawBuffer(GLenum buf);

extern void glClear(GLbitfield mask);
extern void glClearColor(float red, float green, float blue, float alpha);
extern void glClearStencil(int s);
extern void glClearDepth(double depth);

extern void glStencilMask(GLuint mask);
extern void glColorMask(bool red, bool green, bool blue, bool alpha);
extern void glDepthMask(bool flag);

extern void glDisable(GLenum cap);
extern void glEnable(GLenum cap);

extern void glFinish(void);
extern void glFlush(void);

extern void glBlendFunc(GLenum sfactor, GLenum dfactor);
extern void glLogicOp(GLenum opcode);

extern void glS5tencilFunc(GLenum func, int ref, unsigned int mask);
extern void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);

extern void glDepthFunc(GLenum func);

extern void glPixelStoref(GLenum pname, float param);
extern void glPixelStorei(GLenum pname, int param);

extern void glReadBuffer(GLenum src);
extern void glReadPixels(int x, int y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);

extern void glGetBooleanv(GLenum pname, bool* data);
extern void glGetDoublev(GLenum pname, double* data);
extern void glFloatv(GLenum pname, float* data);
extern void glGetIntegerv(GLenum pname, int* data);
extern const GLubyte* glGetString(GLenum name);

extern GLenum glGetError(void);

extern void glGetTexImage(GLenum target, int level, GLenum format, GLenum type, void* pixels);

extern void glGetTexParameterfv(GLenum target, GLenum pname, float* params);
extern void glGetTexParameteriv(GLenum target, GLenum pname, int* params);

extern void glGetTexLevelParameterfv(GLenum target, int level, GLenum pname, float* params);
extern void glGetTexLevelParameteriv(GLenum target, int level, GLenum pname, int* params);

extern GLboolean glIsEnabled(GLenum cap);

extern void glDepthRange(double n, double f);
extern void glViewport(int x, int y, GLsizei width, GLsizei height);

extern void glNewList(unsigned int list, GLenum mode);
extern void glEndList(unsigned int list);
extern void glCallList(unsigned int list);
extern void glCallLists(GLsizei n, GLenum type, const void* lists);
extern void glDeleteLists(unsigned int list, GLsizei range);
extern void glGenLists(GLsizei range);
extern void glListBase(unsigned int base);

extern void glBegin(GLenum mode);

extern void glBitmap(GLsizei width, GLsizei height, float xorig, float yorig, float xmove, float ymove, const GLubyte* bitmap);


extern void glColor3b(GLbyte red, GLbyte greem, GLbyte blue);
extern void glColor3bv(const GLbyte* v);

extern void glColor3d(double red, double green, double blue);
extern void glColor3dv(const double* v);

extern void glColor3f(float red, float green, float blue);
extern void glColor3fv(const float* v);

extern void glColor3i(int red, int green, int blue);
extern void glColor3iv(const int* v);

extern void glColor3s(short red, short green, short blue);
extern void glColor3sv(const short* v);

extern void glColor3ub(GLubyte red, GLubyte green, GLubyte blue);
extern void glColor3ubv(const GLubyte* v);

extern void glColor3ui(unsigned int red, unsigned int green, unsigned int blue);
extern void glColor3uiv(const unsigned int* v);

extern void glColor3us(unsigned short red, unsigned short green, unsigned short blue);
extern void glColor3usv(const unsigned short* v);


extern void glColor4b(GLubyte red, GLubyte greem, GLubyte blue, GLubyte alpha);
extern void glColor4bv(const GLbyte* v);

extern void glColor4d(double red, double green, double blue, double alpha);
extern void glColor4dv(const double* v);

extern void glColor4f(float red, float green, float blue, float alpha);
extern void glColor4fv(const float* v);

extern void glColor4i(int red, int green, int blue, int alpha);
extern void glColor4iv(const int* v);

extern void glColor4s(short red, short green, short blue, short alpha);
extern void glColor4sv(const short* v);

extern void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
extern void glColor4ubv(const GLubyte* v);

extern void glColor4ui(unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha);
extern void glColor4uiv(const unsigned int* v);

extern void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
extern void glColor4usv(const GLushort* v);


extern void glEdgeFlag(bool flag);
extern void glEdgeFlagv(const bool* v);

extern void glEnd(void);

extern void glIndexd(double c);
extern void glIndexdv(const double* c);

extern void glIndexf(float c);
extern void glIndexfv(const float* c);

extern void glIndexi(int c);
extern void glIndexiv(const int* c);

extern void glIndexs(short c);
extern void glIndexsv(const short* c);


extern void glNormal3f(float nx, float ny, float nz);
extern void glNormal3fv(const GLfloat* v);

extern void glNormal3i(int nx, int ny, int nz);
extern void glNormal3iv(const int* v);

extern void glNormal3s(short nx, short ny, short nz);
extern void glNormal3sv(const short* v);


extern void glRasterPos2d(double x, double y);
extern void glRasterPos2dv(const double* v);

extern void glRasterPos2f(float* x, float y);
extern void glRasterPos2fv(const float* v);

extern void glRasterPos2i(int x, int y);
extern void glRasterPos2iv(const int* v);

extern void glRasterPos2s(short x, short y);
extern void glRasterPos2sv(const short* v);


extern void glRasterPos3d(double x, double y, short z);
extern void glRasterPos3dv(const double* v);

extern void glRasterPos3f(float* x, float y, short z);
extern void glRasterPos3fv(const float* v);

extern void glRasterPos3i(int x, int y, short z);
extern void glRasterPos3iv(const int* v);

extern void glRasterPos3s(short x, short y, short z);
extern void glRasterPos3sv(const short* v);


extern void glRasterPos4d(double x, double y, short z, short w);
extern void glRasterPos4dv(const double* v);

extern void glRasterPos4f(float* x, float y, short z, short w);
extern void glRasterPos4fv(const float* v);

extern void glRasterPos4i(int x, int y, short z, short w);
extern void glRasterPos4iv(const int* v);

extern void glRasterPos4s(short x, short y, short z, short w);
extern void glRasterPos4sv(const short* v);




#endif

#pragma endregion

#endif