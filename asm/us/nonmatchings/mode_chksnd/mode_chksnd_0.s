.syntax unified
	.align 2, 0
	.global mode_chksnd_0
	.thumb
	.thumb_func
	.type mode_chksnd_0, %function
mode_chksnd_0: @ 0800B9F4
	push {r4, lr}
	bl func_08004DB0
	ldr r1, _0800BA1C @ =0x020348B4
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r4, _0800BA20 @ =0x020348A0
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl func_08000E64
	ldr r1, _0800BA24 @ =0x09EE9190
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_08000E14
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800BA1C: .4byte 0x020348B4
_0800BA20: .4byte 0x020348A0
_0800BA24: .4byte 0x09EE9190
.syntax divided
