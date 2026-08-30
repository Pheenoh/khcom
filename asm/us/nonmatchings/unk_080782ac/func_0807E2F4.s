.syntax unified
	.align 2, 0
	.global func_0807E2F4
	.thumb
	.thumb_func
	.type func_0807E2F4, %function
func_0807E2F4: @ 0807E2F4
	ldr r0, _0807E310 @ =0x02034AAC
	ldr r1, [r0, #0x00]
	cmp r1, #0x00
	beq _0807E32C
	ldr r0, [r1, #0x78]
	ldr r1, _0807E314 @ =0x01000044
	ands r0, r1
	cmp r0, r1
	bne _0807E31C
	ldr r0, _0807E318 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xE8
	movs r1, #0x01
	b _0807E332
_0807E310: .4byte 0x02034AAC
_0807E314: .4byte 0x01000044
_0807E318: .4byte 0x02039DD4
_0807E31C:
	ldr r0, _0807E328 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xE8
	movs r1, #0x00
	b _0807E332
	.byte 0x00, 0x00
_0807E328: .4byte 0x02039DD4
_0807E32C:
	ldr r0, _0807E338 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xE8
_0807E332:
	strb r1, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_0807E338: .4byte 0x02039DD4
.syntax divided
