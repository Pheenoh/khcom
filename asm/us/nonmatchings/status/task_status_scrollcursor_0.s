.syntax unified
	.align 2, 0
	.global task_status_scrollcursor_0
	.thumb
	.thumb_func
	.type task_status_scrollcursor_0, %function
task_status_scrollcursor_0: @ 080D8890
	push {r4, r5, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x0C]
	ldr r5, _080D88C8 @ =0x09EF6908
	adds r0, r5, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D88CC @ =0x097A2394
	bl func_080028F8
	str r0, [r4, #0x00]
	ldr r0, _080D88D0 @ =0x0984B1F8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldr r0, [r5, #0x10]
	str r0, [r4, #0x08]
	adds r0, r4, #0x0
	bl func_080D885C
	strh r0, [r4, #0x12]
	pop {r4, r5}
	pop {r0}
	bx r0
_080D88C8: .4byte 0x09EF6908
_080D88CC: .4byte 0x097A2394
_080D88D0: .4byte 0x0984B1F8
.syntax divided
