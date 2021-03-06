/*
 * Copyright 2011 Andrew H. Armenia.
 * 
 * This file is part of openreplay.
 * 
 * openreplay is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * openreplay is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with openreplay.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _KEYDAEMON_SVG_SUBPROCESS_CHARACTER_GENERATOR_H
#define _KEYDAEMON_SVG_SUBPROCESS_CHARACTER_GENERATOR_H

#include "character_generator.h"
#include "cairo_frame.h"

class SvgSubprocessCharacterGenerator : public CharacterGenerator {
    public:
        SvgSubprocessCharacterGenerator(const char *cmd, 
                unsigned int dirty_level = 0);
        ~SvgSubprocessCharacterGenerator( );
        unsigned int dirty_level( ) { return _dirty_level; }
        void paint_gl( );
    protected:
        virtual void run_thread( );
        void do_fork( );

        void request( );
        char *read_svg(size_t length);



        char *_cmd;

        int send_fd, recv_fd;
        unsigned int _dirty_level;

        RawFrame* _frame;
        RawFrame* _old_frame;
        uint8_t _alpha;

        Mutex mut;
};

#endif
