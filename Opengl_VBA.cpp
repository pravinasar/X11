// Define vertices (x, y, z) and colors (r, g, b)
GLfloat vertices[] = {
   0.0f, 0.5f, 0.0f, // Vertex 1
  -0.5f, -0.5f, 0.0f, // Vertex 2
   0.5f, -0.5f, 0.0f // Vertex 3
};
GLfloat colors[] = {
   1.0f, 0.0f, 0.0f, // Red
   0.0f, 1.0f, 0.0f, // Green
   0.0f, 0.0f, 1.0f // Blue
};
// Enable vertex and color arrays
glEnableClientState(GL_VERTEX_ARRAY);
glEnableClientState(GL_COLOR_ARRAY);
// Specify pointers to the vertex and color data
glVertexPointer(3, GL_FLOAT, 0, vertices);
glColorPointer(3, GL_FLOAT, 0, colors);
// Draw the triangle
glDrawArrays(GL_TRIANGLES, 0, 3);
// Disable arrays after rendering
glDisableClientState(GL_VERTEX_ARRAY);
glDisableClientState(GL_COLOR_ARRAY);
