/*
 * CC3GLView-GL.h
 *
 * cocos3d 2.0.0
 * Author: Bill Hollings
 * Copyright (c) 2010-2014 The Brenwill Workshop Ltd. All rights reserved.
 * http://www.brenwill.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * http://en.wikipedia.org/wiki/MIT_License
 */

/** @file */	// Doxygen marker

#import "CC3Environment.h"

#if CC3_OGL

#import "CCGLView.h"
#import "CC3RenderSurfaces.h"
#import	"CC3OSExtensions.h"

// Define the framebuffer and renderbuffer classes underlying this view
#define CC3ViewFramebufferClass			CC3OSXOnScreenGLFramebuffer
#define CC3ViewColorRenderbufferClass	CC3OSXOnScreenGLRenderbuffer
#define CC3ViewDepthRenderbufferClass	CC3OSXOnScreenGLRenderbuffer


#pragma mark -
#pragma mark CC3GLView

/**
 * A UIView specialized for use by both cocos3d and cocos2d.
 *
 * The UIView displaying 3D content must be of this type.
 */
@interface CC3GLView : CCGLView {
	CC3GLViewSurfaceManager* _surfaceManager;
	GLenum _colorFormat;
	GLenum _depthFormat;
	GLuint _requestedSamples;
}

/** The underlying view rendering surface. */
@property(nonatomic, strong, readonly) CC3GLViewSurfaceManager* surfaceManager;

/** Returns the GL color format of the pixels. */
@property(nonatomic, readonly) GLenum colorFormat;

/** Returns the GL depth format of the pixels. */
@property(nonatomic, readonly) GLenum depthFormat;

/**
 * Returns the number of samples that was requested to be used to define each pixel.
 *
 * This may return a value that is different than the value returned by the pixelSamples
 * property because that property is limited by the capabilities of the platform.
 */
@property(nonatomic, readonly) GLuint requestedSamples;

/**
 * Returns the actual number of samples used to define each pixel.
 *
 * This may return a value that is different than the value returned by the requestedSamples
 * property because this property is limited by the capabilities of the platform.
 */
@property(nonatomic, readonly) GLuint pixelSamples;

/** The OpenGL context used by this view. */
@property(nonatomic, strong, readonly) CC3GLContext* context;

/** Compatibility with iOS view signature. This implementation does nothing under OSX. */
-(void) addGestureRecognizer: (UIGestureRecognizer*) gesture;

/** Compatibility with iOS view signature. This implementation does nothing under OSX. */
-(void) removeGestureRecognizer: (UIGestureRecognizer*) gesture;

@end

/** Returns the GL color format enum corresponding to the specified number of color and alpha bit planes. */
GLenum CC3GLColorFormatFromBitPlanes(GLint colorCount, GLint alphaCount);

/** Returns the GL depth format enum corresponding to the specified number of depth and stencil bit planes. */
GLenum CC3GLDepthFormatFromBitPlanes(GLint depthCount, GLint stencilCount);

#endif	// CC3_OGL