#include "myglwidget.h"
#include <GL/glut.h>

MYGLWidget::MYGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    static bool glutInitialized = false;
    if (!glutInitialized) {
        int argc = 1;
        char *argv[1] = {(char *)"Something"};
        glutInit(&argc, argv);  // 初始化GLUT
        glutInitialized = true;
    }
}

MYGLWidget::~MYGLWidget()
{
}

// 初始化OpenGL：设置OpenGL函数并启用深度测试
void MYGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
}

// 调整视口和投影矩阵
void MYGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);  // 设置视口
    glMatrixMode(GL_PROJECTION);  // 切换到投影矩阵模式
    glLoadIdentity();  // 重置投影矩阵
    gluPerspective(45.0, w / static_cast<double>(h), 0.1, 100.0);  // 设置透视投影
    glMatrixMode(GL_MODELVIEW);  // 切换回模型视图矩阵模式
}

// 绘制函数
void MYGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // 清除颜色和深度缓冲区
    glLoadIdentity();  // 重置模型视图矩阵

    glTranslatef(0.0f, 0.0f, -5.0f);  // 移动场景，以便能看到茶壶

    glColor3f(0.0f, 1.0f, 0.0f);  // 设置茶壶的颜色
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);  // 设置视点

    glutSolidTeapot(2.0);  // 渲染一个大小为2.0的茶壶

    glFlush();
}
