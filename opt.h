/*
 * opt.h
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

#ifndef	__OPT_H__
#define	__OPT_H__

#include <stdbool.h>

enum OptionBtrfsDefrag {
        OPTION_BTRFS_DEFRAG_NONE = 0,
        OPTION_BTRFS_DEFRAG_SOURCE = 1,
        // TODO: Add another value for defragmenting every hashed file.
};

struct btrfs_options {
        enum OptionBtrfsDefrag defrag;
        // TODO: Add options for a extent size threshold and for a compression
        // type.
};

struct options {
	int run_dedupe;
	bool recurse_dirs : 1;
	unsigned int io_threads;
	unsigned int cpu_threads;
	bool skip_zeroes : 1;
	bool only_whole_files : 1;
	bool do_block_hash : 1;
	bool dedupe_same_file : 1;
	unsigned int batch_size;
	bool fdupes_mode : 1;
	char *hashfile;
        struct btrfs_options btrfs;
};

extern struct options options;

#endif	/* __OPT_H__ */
