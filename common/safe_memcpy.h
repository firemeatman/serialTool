
#ifndef SAFE_MEMCPY_H
#define SAFE_MEMCPY_H

#include <stdint.h>
#include <string.h>
static inline bool between(const uint8_t *start, const uint8_t *end, const uint8_t *p) {
    return (p < end) && (p >= start); // 注意是p < end不是p <= end
}
static inline bool safe_check(void *dst, size_t len, const void *start, const void *end) {
    if (len < 1) {
        return false;
    }
    if (!dst || !start || !end) {
        return false;
    }
    void *last_pos = ((uint8_t *)dst) + len - 1;
    if (last_pos < dst) {    // last_pos不能小于dst
        return false;
    }
    return between((uint8_t *)start, (uint8_t *)end, (uint8_t *)dst) &&     // dst在start与end之间
           between((uint8_t *)start, (uint8_t *)end, (uint8_t *)last_pos);  // last_pos即待拷贝区间最后元素地址也必须在start与end之间
}


// dst指向目的地址
// src指向源地址
// len是待拷贝的字节数
// start指向目的地址开始地址
// end指向目的地址结束地址 即最后一个元素的后一个地址

static inline bool safe_memcpy(void *dst, const void *src, size_t len, const void *start, const void *end) {
    if (!safe_check(dst, len, start, end)) {
        return false;
    }
    if (!src) {
        return false;
    }
    memcpy(dst, src, len);
    return true;
}

#endif // SAFE_MEMCPY_H
