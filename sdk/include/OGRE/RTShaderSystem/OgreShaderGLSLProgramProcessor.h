/*
-----------------------------------------------------------------------------
This source file is part of OGRE
(Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org

Copyright (c) 2000-2009 Torus Knot Software Ltd
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef _ShaderGLSLProgramProcessor_
#define _ShaderGLSLProgramProcessor_

#include "OgreShaderPrerequisites.h"
#include "OgreShaderProgramProcessor.h"
#include "OgreStringVector.h"


namespace Ogre {
namespace RTShader {

/** \addtogroup Core
*  @{
*/
/** \addtogroup RTShader
*  @{
*/

/** GLSL Language program processor class.
*/
class GLSLProgramProcessor : public ProgramProcessor
{

// Interface.
public:	

	/** Class constructor.
	@param type The type of this program.
	*/
	GLSLProgramProcessor			();

	/** Class destructor */
	virtual ~GLSLProgramProcessor	();

	/** Return the target language of this processor. */
	virtual const String&		getTargetLanguage	() const { return TargetLanguage; }

	/** Called before creation of the GPU programs.
	Do several preparation operation such as validation, register compaction and specific target language optimizations.
	@param programSet The program set container.
	Return true on success.
	*/
	virtual bool				preCreateGpuPrograms			(ProgramSet* programSet);

	/** Called after creation of the GPU programs.
	@param programSet The program set container.
	Return true on success.
	*/
	virtual bool				postCreateGpuPrograms			(ProgramSet* programSet);


private:

	/** Bind texture samplers. */
	void						bindTextureSamplers				(Program* pCpuProgram, GpuProgramPtr pGpuProgram);

	/** Compiles sub shaders (only if the not exists) and attach them to the main gpu program. */
	void						bindSubShaders					(Program* program, GpuProgramPtr pGpuProgram);

	static String TargetLanguage;

	StringVector	mLibraryPrograms;		// The list of created library shaders.

};


/** @} */
/** @} */

}
}

#endif

