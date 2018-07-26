/*
 * This structure helps apfs_normalize_next() to retrieve one normalized
 * (and case-folded) UTF-32 character at a time from a UTF-8 string.
 */
struct apfs_unicursor {
	const char *utf8curr;	/* Start of UTF-8 to decompose and reorder */
	int length;		/* Length of normalization until next starter */
	int last_pos;           /* Offset in substring of last char returned */
	u8 last_ccc;		/* CCC of the last character returned */
};

extern void apfs_init_unicursor(struct apfs_unicursor *cursor,
				 const char *utf8str);
extern unicode_t apfs_normalize_next(struct apfs_unicursor *cursor);

#endif	/* _APFS_UNICODE_H */
