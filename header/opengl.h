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

#pragma endregion

#endif