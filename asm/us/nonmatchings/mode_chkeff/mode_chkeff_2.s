.syntax unified
	.align 2, 0
	.global mode_chkeff_2
	.thumb
	.thumb_func
	.type mode_chkeff_2, %function
mode_chkeff_2: @ 0800BF74
	push {r4, lr}
	ldr r4, _0800BF8C @ =0x020348B8
	ldr r0, [r4, #0x00]
	bl TaskPoolDestroy
	ldr r0, [r4, #0x00]
	bl EwramFree
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800BF8C: .4byte 0x020348B8
.syntax divided
