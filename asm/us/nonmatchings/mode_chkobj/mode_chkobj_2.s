.syntax unified
	.align 2, 0
	.global mode_chkobj_2
	.thumb
	.thumb_func
	.type mode_chkobj_2, %function
mode_chkobj_2: @ 0800B9C4
	push {r4, lr}
	ldr r4, _0800B9F0 @ =0x0203489C
	ldr r0, [r4, #0x00]
	bl func_08000F0C
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x1C]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x20]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	bl func_080009C4
	bl func_080609A0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800B9F0: .4byte 0x0203489C
.syntax divided
