.syntax unified
	.align 2, 0
	.global task_evt_obj_0
	.thumb
	.thumb_func
	.type task_evt_obj_0, %function
task_evt_obj_0: @ 0801CEAC
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r5, [r1, #0x00]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x00]
	ldrh r0, [r5, #0x00]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080028F8
	str r0, [r4, #0x04]
	ldr r0, [r5, #0x08]
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	adds r5, r4, #0x0
	adds r5, #0x0C
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r1, [r4, #0x00]
	str r5, [r1, #0x18]
	ldr r0, [r4, #0x08]
	ldrh r0, [r0, #0x06]
	strh r0, [r1, #0x1C]
	adds r0, r4, #0x0
	bl func_0801CE70
	adds r5, #0x18
	adds r0, r5, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _0801CF08 @ =0x09EDADE0
	ldr r2, [r4, #0x00]
	adds r0, r5, #0x0
	bl func_08000E14
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801CF08: .4byte 0x09EDADE0
.syntax divided
