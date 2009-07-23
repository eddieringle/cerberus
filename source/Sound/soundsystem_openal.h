/*
 * Copyright (c) 2009 Steven Noonan <steven@uplinklabs.net>
 *                and Miah Clayton <miah@ferrousmoon.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __included_soundsystem_openal_h
#define __included_soundsystem_openal_h

#ifdef USE_OPENAL

#ifdef TARGET_OS_WINDOWS
#    include <al.h>
#   include <alc.h>
#elif defined(TARGET_OS_MACOSX)
#    include <OpenAL/al.h>
#   include <OpenAL/alc.h>
#else
#    include <AL/al.h>
#    include <AL/alc.h>
#endif

class OpenALSoundSystem : public SoundSystem
{
protected:
    Data::LList<ALuint>                            m_usedSources;
    Data::LList<ALuint>                            m_freeSources;
    Data::RedBlackTree<const char *, ALuint>       m_buffers;
    Data::DArray<Data::LList<std::string> *>       m_queues;
    ALCcontext*                                    m_context;
    ALCdevice*                                     m_device;

    ALuint              AcquireSource ();
public:
    OpenALSoundSystem();
    virtual ~OpenALSoundSystem();

    virtual void       AddQueue    ( Data::LList<std::string> *_queue );
    virtual bool       IsPlaying   ( const char *_soundName );
    virtual int        LoadWave    ( const char *_soundName );
    virtual int        PlaySound   ( const char *_soundName, short _distX, short _distY );
    virtual void       Update      ();
};

#endif

#endif
