# Nacy Engine

## Introduction
This is a 2D OpenGL Game Engine

We suggest to Use C++17 and above version

## Build

* clone this project
* you need to the NacyEngine Dir to unzip The `Dependencies.zip` to a `Dependencies` Dir
* Open your visual studio import the project

## Framework

1. Scene Manager

>Use The Manager to add, update, render GameObject

2. Game Application

>Create Application To Start Game Engine and Init Game Window

3. Event Handler

>Invoke Window and Game Event Function

4. Resource Manager

> Load And Get User Custom Assets. For example (`Textures` `Audio` `Shader` `Font` `Data`)

5. Simple GCS

> A easy esc `GameObject -- Component -- System`


## How to use

Create An Application

```c++
#include <NacyEngine.h>
using namespace Nacy;
void main()
{
    //Created App
    auto app = new Application(Application::CreateGameWindow(WindowConfig("Game",true,1270,800,true,true)));
}
```

Start Engine

```c++
void main()
{
    //Created App...

    //Start App
    app->Start();
    app->Stop();
}
```

Load Assets
```C++

void main()
{
    //Created App...

    //Load Resource
    ResourceManager::LoadTexture("<file_path>",<has_alpha_color>,"<custom_name>");
    ResourceManager::LoadFont("<file_path>", <font_size>, "<custom_name>");
    ...

    //Start App...
}
```
Display A Scene

```c++

class MyScene : public Scene
{
    void Init() override {}
    void Update() override {}
    void DrawBackground() override {}

}
void main()
{
    
    SceneManager::GetInstance()->DisplayScene(new MyScene);
}

```

>If you want to know more api about Nacy Engine please visit xxx.com

## Contributions
[X_huihui](https://github.com/xiaohuihui1022)

[YouM](https://github.com/YOM667)
