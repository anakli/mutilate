#ifndef BINARY_PROTOCOL_H
#define	BINARY_PROTOCOL_H

#define CMD_GET  0x00
#define CMD_SET  0x01
#define CMD_SASL 0x21

#define RESP_OK 0x00
#define RESP_SASL_ERR 0x20

typedef struct __attribute__ ((__packed__)) {
  uint8_t magic;
  uint8_t opcode;
  uint16_t key_len;

  uint8_t extra_len;
  uint8_t data_type;
  union {
   uint16_t vbucket; // request use
   uint16_t status;  // response use
  };

  uint32_t body_len;
  uint32_t opaque;
  uint64_t version;

  // Used for set only.
  uint64_t extras;
} binary_header_t;


// REFLEX PROTCOL

//FIXME: This conflicts with the kernel definition
struct bio_vec {
	struct page     *bv_page;
	unsigned int    bv_len;
	unsigned int    bv_offset;
};

typedef struct __attribute__ ((__packed__)) {
  uint16_t magic;
  uint16_t opcode;
  void *req_handle;
  struct bio_vec bvec_handle;
  unsigned long lba;
  unsigned int lba_count;
} binary_header_blk_t;



#endif /* BINARY_PROTOCOL_H */
