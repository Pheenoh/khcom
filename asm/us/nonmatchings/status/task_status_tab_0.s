.syntax unified
	.align 2, 0
	.global task_status_tab_0
	.thumb
	.thumb_func
	.type task_status_tab_0, %function
task_status_tab_0: @ 080D7BA8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x18]
	ldr r5, _080D7C0C @ =0x09EF6920
	adds r0, r5, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D7C10 @ =0x097A24A6
	bl func_080028F8
	str r0, [r4, #0x00]
	ldr r0, _080D7C14 @ =0x0984B218
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	ldr r0, [r4, #0x18]
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x10]
	ldr r5, _080D7C18 @ =0x09EF6934
	adds r0, r5, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D7C1C @ =0x097A28DA
	bl func_080028F8
	str r0, [r4, #0x04]
	ldr r0, _080D7C20 @ =0x0984B238
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x0C]
	ldr r0, [r4, #0x18]
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x14]
	pop {r4, r5}
	pop {r0}
	bx r0
_080D7C0C: .4byte 0x09EF6920
_080D7C10: .4byte 0x097A24A6
_080D7C14: .4byte 0x0984B218
_080D7C18: .4byte 0x09EF6934
_080D7C1C: .4byte 0x097A28DA
_080D7C20: .4byte 0x0984B238
.syntax divided
