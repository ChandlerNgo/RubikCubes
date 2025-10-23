# Rubik's Cube Project

This project uses **OpenGL** with **GLEW**, **GLM**, and **GLFW** to render a 3x3 Rubik's Cube.  

The plan is to expand to NxN cube once 3x3 is complete.

---

## 1. Set Environment Variables

Before building, set these environment variables so the compiler can find the libraries:

| Variable | What it is | Example |
|----------|------------|---------|
| `GLEW_DIR` | GLEW folder (headers + library) | `~/libs/glew-2.1.0` |
| `GLM_INCLUDE_DIR` | GLM folder (headers only) | `~/libs/glm-0.9.9.7` |

GLFW installed system-wide.

**Linux/macOS Example:**

```bash
export GLEW_DIR=~/Desktop/glew-2.1.0
export GLM_INCLUDE_DIR=~/Desktop/glm-0.9.9.7