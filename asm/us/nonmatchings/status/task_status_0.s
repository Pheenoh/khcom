.syntax unified
	.align 2, 0
	.global task_status_0
	.thumb
	.thumb_func
	.type task_status_0, %function
task_status_0: @ 080D7574
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r0, _080D75FC @ =0x02034EFC
	str r4, [r0, #0x00]
	movs r5, #0x00
	str r5, [r4, #0x14]
	ldr r6, _080D7600 @ =0x02034F00
	strb r5, [r6, #0x00]
	strh r5, [r4, #0x1A]
	strh r5, [r4, #0x1C]
	adds r0, r4, #0x0
	movs r1, #0x09
	bl func_08000E64
	ldr r1, _080D7604 @ =0x09EF4FE0
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_08000E14
	ldr r1, _080D7608 @ =0x09EF4F38
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_08000E14
	ldr r0, _080D760C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080D75C6
	ldr r1, _080D7610 @ =0x09EF4F20
	adds r2, r4, #0x0
	adds r2, #0x14
	adds r0, r4, #0x0
	bl func_08000E14
	ldr r1, _080D7614 @ =0x09EF4F50
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl func_08000E14
_080D75C6:
	ldr r1, _080D7618 @ =0x09EF4F80
	adds r2, r4, #0x0
	adds r2, #0x14
	adds r0, r4, #0x0
	bl func_08000E14
	ldr r1, _080D761C @ =0x09EF4F98
	adds r2, r4, #0x0
	adds r2, #0x1C
	adds r0, r4, #0x0
	bl func_08000E14
	ldr r1, _080D7620 @ =0x09EF4FB0
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl func_08000E14
	bl func_080D82D4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080D7624
	ldr r0, [r4, #0x14]
	mvns r0, r0
	strh r0, [r4, #0x1A]
	b _080D7626
	.byte 0x00, 0x00
_080D75FC: .4byte 0x02034EFC
_080D7600: .4byte 0x02034F00
_080D7604: .4byte 0x09EF4FE0
_080D7608: .4byte 0x09EF4F38
_080D760C: .4byte 0x02039BB0
_080D7610: .4byte 0x09EF4F20
_080D7614: .4byte 0x09EF4F50
_080D7618: .4byte 0x09EF4F80
_080D761C: .4byte 0x09EF4F98
_080D7620: .4byte 0x09EF4FB0
_080D7624:
	strh r5, [r4, #0x1A]
_080D7626:
	ldr r1, _080D7644 @ =0x09EF4F68
	adds r2, r4, #0x0
	adds r2, #0x1A
	adds r0, r4, #0x0
	bl func_08000E14
	ldr r1, _080D7648 @ =0x02034F02
	ldrh r0, [r4, #0x1C]
	ldrh r4, [r4, #0x1A]
	adds r0, r0, r4
	strh r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D7644: .4byte 0x09EF4F68
_080D7648: .4byte 0x02034F02
.syntax divided
