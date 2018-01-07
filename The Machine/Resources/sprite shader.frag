#version 410 core

in vec2 fragTexCoord;

uniform sampler2D tex;

out vec4 color;

void main() {
  color = texture(tex, fragTexCoord);
  gl_FragDepth = (color.a == 0.0 ? 1.0 : gl_FragCoord.z);
}
