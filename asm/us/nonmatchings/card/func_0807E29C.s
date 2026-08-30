.syntax unified
	.align 2, 0
	.global func_0807E29C
	.thumb
	.thumb_func
	.type func_0807E29C, %function
func_0807E29C: @ 0807E29C
	ldr r0, _0807E2B4 @ =0x02034AAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0807E2B8
	ldr r0, [r0, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x0D
	ands r0, r1
	cmp r0, #0x00
	beq _0807E2B8
	movs r0, #0x01
	b _0807E2BA
_0807E2B4: .4byte 0x02034AAC
_0807E2B8:
	movs r0, #0x00
_0807E2BA:
	bx lr
.syntax divided
