/* libmpdclient
   (c) 2003-2008 The Music Player Daemon Project
   This project's homepage is: http://www.musicpd.org

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   - Neither the name of the Music Player Daemon nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MPD_DB_H
#define MPD_DB_H

#include <mpd/connection.h>
#include <mpd/tag.h>

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @param connection a #mpd_connection
 * @param type The type of the tag to get
 *
 * Use this function to get the next tagi of o given type.
 * NULL means there are no more.
 */
char *mpd_get_next_tag(struct mpd_connection *connection,
		       enum mpd_tag_type type);

/**
 * @param connection a #mpd_connection
 * @param type The tag type of the constraint
 * @param value The value of the constaint
 *
 * Add a constraint to a search.
 */
void mpd_search_add_constraint(struct mpd_connection *connection,
			       enum mpd_tag_type type,
			       const char *value);

/**
 * @param connection a #mpd_connection
 *
 * Starts the real search with constraints added with
 * mpd_search_add_constraint.
 */
void mpd_search_commit(struct mpd_connection *connection);


/**
 * @param connection a #mpd_connection
 * @param exact if to match exact
 *
 * Search for songs in the db given certain constraints
 * Use this method with mpd_search_add_constraint and mpd_search_commit
 * Use mpd_getNextInfoEntity to get results of this method
 */
void mpd_search_db_songs(struct mpd_connection *connection,
			 bool exact);

/**
 * @param connection a #mpd_connection
 * @param exact if to match exact
 *
 * Search for songs in the playlist given certain constraints
 * Use this method with mpd_search_add_constraint and mpd_search_commit
 * Use mpd_getNextInfoEntity to get results of this method
 */
void mpd_search_playlist_songs(struct mpd_connection *connection,
			       bool exact);

/**
 * @param connection a #mpd_connection
 * @param type The type of the tags to search for
 *
 * Search for tags in the db given certain constraints
 * Use this method with mpd_search_add_constraint and mpd_search_commit
 * Use mpd_get_next_tag to get results of this method
 */ 
void mpd_search_db_tags(struct mpd_connection *connection,
			enum mpd_tag_type type);

/**
 * @param connection a #mpd_connection
 *
 * Counts the number of songs and the total playtime given certain constraints
 * Use this method with mpd_search_add_constraint and mpd_search_commit
 * Use mpd_get_stats to get results of this method
 */ 
void mpd_count_db_songs(struct mpd_connection *connection);


#ifdef __cplusplus
}
#endif

#endif