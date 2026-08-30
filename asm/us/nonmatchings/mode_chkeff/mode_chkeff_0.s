.syntax unified
	.align 2, 0
	.global mode_chkeff_0
	.thumb
	.thumb_func
	.type mode_chkeff_0, %function
mode_chkeff_0: @ 0800BB2C
	push {r4, lr}
	ldr r4, _0800BC34 @ =0x020348B8
	movs r0, #0x28
	bl func_08000918
	str r0, [r4, #0x00]
	bl func_08004E64
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x07
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x01
	movs r2, #0x0C
	movs r3, #0x08
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x02
	movs r2, #0x1C
	movs r3, #0x0A
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x10
	movs r2, #0x10
	bl func_080057A0
	movs r0, #0x02
	movs r1, #0x00
	bl func_080055C8
	movs r0, #0x00
	movs r1, #0x01
	bl func_080055C8
	movs r0, #0x01
	movs r1, #0x02
	bl func_080055C8
	ldr r1, _0800BC38 @ =0x08C6B0C4
	ldr r2, _0800BC3C @ =0x00007C20
	movs r0, #0x01
	bl func_080050B8
	ldr r1, _0800BC40 @ =0x08F683C4
	movs r0, #0x01
	movs r2, #0x20
	bl func_080050DC
	ldr r1, _0800BC44 @ =0x08EEE384
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl func_0800510C
	movs r0, #0x08
	movs r1, #0x01
	bl func_080062F4
	movs r0, #0x09
	movs r1, #0x01
	bl func_080062F4
	movs r0, #0x0A
	movs r1, #0x01
	bl func_080062F4
	movs r0, #0x0B
	movs r1, #0x01
	bl func_080062F4
	movs r0, #0x0C
	movs r1, #0x01
	bl func_080062F4
	movs r0, #0x0D
	movs r1, #0x01
	bl func_080062F4
	movs r0, #0x0E
	movs r1, #0x01
	bl func_080062F4
	movs r0, #0x0F
	movs r1, #0x01
	bl func_080062F4
	movs r1, #0x80
	lsls r1, r1, #0x08
	movs r0, #0x02
	movs r2, #0x80
	bl func_080065FC
	ldr r0, [r4, #0x00]
	movs r1, #0x01
	bl func_08000E64
	ldr r0, [r4, #0x00]
	ldr r1, _0800BC48 @ =0x09EE9190
	movs r2, #0x00
	bl func_08000E14
	ldr r0, [r4, #0x00]
	movs r2, #0x00
	movs r1, #0x00
	strh r1, [r0, #0x14]
	strb r2, [r0, #0x16]
	ldr r0, [r4, #0x00]
	strh r1, [r0, #0x18]
	strh r1, [r0, #0x1A]
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x20]
	strb r2, [r0, #0x1C]
	ldr r1, [r4, #0x00]
	movs r0, #0x10
	strh r0, [r1, #0x24]
	strh r0, [r1, #0x26]
	ldr r0, _0800BC4C @ =0x09ED9A1C
	ldr r0, [r0, #0x00]
	movs r1, #0x78
	movs r2, #0x50
	bl func_08006778
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800BC34: .4byte 0x020348B8
_0800BC38: .4byte 0x08C6B0C4
_0800BC3C: .4byte 0x00007C20
_0800BC40: .4byte 0x08F683C4
_0800BC44: .4byte 0x08EEE384
_0800BC48: .4byte 0x09EE9190
_0800BC4C: .4byte 0x09ED9A1C
.syntax divided
