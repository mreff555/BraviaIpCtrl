

// #include <braviaCommands.hpp> // The actual API
// #include <braviaIpCtrl.hpp>   // Temporary
// #include <log.hpp>

// #include <imgui.h>
// #include <imgui_impl_glfw.h>
// #include <imgui_impl_metal.h>

// #include <stdio.h>
// #include <cstring>
// #include <iomanip>
// #include <iostream>

// #define GLFW_INCLUDE_NONE
// #define GLFW_EXPOSE_NATIVE_COCOA
// #include <GLFW/glfw3.h>
// #include <GLFW/glfw3native.h>

// #import <Metal/Metal.h>
// #import <QuartzCore/QuartzCore.h>

// static void glfw_error_callback(int error, const char* description)
// {
//     fprintf(stderr, "Glfw Error %d: %s\n", error, description);
// }

// int main()
// {
//     IMGUI_CHECKVERSION();
//     ImGui::CreateContext();
//     ImGuiIO& io = ImGui::GetIO(); (void)io;

//     // Setup window
//     glfwSetErrorCallback(glfw_error_callback);
//     if (!glfwInit())
//         return 1;

//     // Create window with graphics context
//     glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
//     GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+Metal
//     example", NULL, NULL); if (window == NULL)
//         return 1;

//     id <MTLDevice> device = MTLCreateSystemDefaultDevice();
//     id <MTLCommandQueue> commandQueue = [device newCommandQueue];

//     // Setup Platform/Renderer backends
//     ImGui_ImplGlfw_InitForOpenGL(window, true);
//     ImGui_ImplMetal_Init(device);

//     NSWindow *nswin = glfwGetCocoaWindow(window);
//     CAMetalLayer *layer = [CAMetalLayer layer];
//     layer.device = device;
//     layer.pixelFormat = MTLPixelFormatBGRA8Unorm;
//     nswin.contentView.layer = layer;
//     nswin.contentView.wantsLayer = YES;

//     MTLRenderPassDescriptor *renderPassDescriptor = [MTLRenderPassDescriptor
//     new];

//     // Our state
//     bool show_demo_window = true;
//     bool show_another_window = false;
//     float clear_color[4] = {0.45f, 0.55f, 0.60f, 1.00f};

//     // Main loop
//     while (!glfwWindowShouldClose(window))
//     {
//         @autoreleasepool
//         {
//             // Poll and handle events (inputs, window resize, etc.)
//             // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard
//             flags to tell if dear imgui wants to use your inputs.
//             // - When io.WantCaptureMouse is true, do not dispatch mouse
//             input data to your main application, or clear/overwrite your copy
//             of the mouse data.
//             // - When io.WantCaptureKeyboard is true, do not dispatch
//             keyboard input data to your main application, or clear/overwrite
//             your copy of the keyboard data.
//             // Generally you may always pass all inputs to dear imgui, and
//             hide them from your application based on those two flags.
//             glfwPollEvents();

//             int width, height;
//             glfwGetFramebufferSize(window, &width, &height);
//             layer.drawableSize = CGSizeMake(width, height);
//             id<CAMetalDrawable> drawable = [layer nextDrawable];

//             id<MTLCommandBuffer> commandBuffer = [commandQueue
//             commandBuffer];
//             renderPassDescriptor.colorAttachments[0].clearColor =
//             MTLClearColorMake(clear_color[0] * clear_color[3], clear_color[1]
//             * clear_color[3], clear_color[2] * clear_color[3],
//             clear_color[3]); renderPassDescriptor.colorAttachments[0].texture
//             = drawable.texture;
//             renderPassDescriptor.colorAttachments[0].loadAction =
//             MTLLoadActionClear;
//             renderPassDescriptor.colorAttachments[0].storeAction =
//             MTLStoreActionStore; id <MTLRenderCommandEncoder> renderEncoder =
//             [commandBuffer
//             renderCommandEncoderWithDescriptor:renderPassDescriptor];
//             [renderEncoder pushDebugGroup:@"ImGui demo"];

//             // Start the Dear ImGui frame
//             ImGui_ImplMetal_NewFrame(renderPassDescriptor);
//             ImGui_ImplGlfw_NewFrame();
//             ImGui::NewFrame();

//             // 1. Show the big demo window (Most of the sample code is in
//             ImGui::ShowDemoWindow()! You can browse its code to learn more
//             about Dear ImGui!). if (show_demo_window)
//                 ImGui::ShowDemoWindow(&show_demo_window);
//     }

// }