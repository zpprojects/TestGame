//
//  Shaders.h
//  TestGame
//
//  Created by Jacob Sawyer on 10/23/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#ifndef TestGame_Shaders_h
#define TestGame_Shaders_h
static const char* basic_vertex_shader_text =
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";

static const char* basic_fragment_shader_text =
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
"}\n";

#endif
