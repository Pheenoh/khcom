.syntax unified
	.align 2, 0
	.global task_btl_badstatus_0
	.thumb
	.thumb_func
	.type task_btl_badstatus_0, %function
task_btl_badstatus_0: @ 08040A84
	push {r4, r5, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	movs r0, #0x00
	str r0, [r4, #0x28]
	str r1, [r4, #0x24]
	movs r0, #0x80
	movs r1, #0x00
	bl func_080028F8
	str r0, [r4, #0x00]
	ldr r0, _08040AD8 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldr r0, _08040ADC @ =0x09611AB8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	ldr r0, [r4, #0x04]
	str r0, [r4, #0x2C]
	adds r5, r4, #0x0
	adds r5, #0x0C
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r0, _08040AE0 @ =0x0813E8F4
	ldr r1, [r4, #0x00]
	str r1, [sp, #0x000]
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
_08040AD8: .4byte 0x08F69BA4
_08040ADC: .4byte 0x09611AB8
_08040AE0: .4byte 0x0813E8F4
.syntax divided
