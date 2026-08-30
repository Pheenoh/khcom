.syntax unified
	.align 2, 0
	.global func_0807E2BC
	.thumb
	.thumb_func
	.type func_0807E2BC, %function
func_0807E2BC: @ 0807E2BC
	ldr r0, _0807E2E4 @ =0x02034AAC
	ldr r2, [r0, #0x00]
	cmp r2, #0x00
	beq _0807E2F0
	ldr r0, [r2, #0x78]
	movs r1, #0x88
	lsls r1, r1, #0x11
	ands r0, r1
	cmp r0, #0x00
	bne _0807E2F0
	ldr r1, [r2, #0x48]
	adds r0, r1, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0807E2EC
	ldr r0, [r1, #0x24]
	ldr r1, _0807E2E8 @ =0x0000FFFF
	adds r0, r0, r1
	b _0807E2F2
_0807E2E4: .4byte 0x02034AAC
_0807E2E8: .4byte 0x0000FFFF
_0807E2EC:
	ldr r0, [r1, #0x24]
	b _0807E2F2
_0807E2F0:
	movs r0, #0x91
_0807E2F2:
	bx lr
.syntax divided
