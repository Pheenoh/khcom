.syntax unified
	.align 2, 0
	.global task_wlogo_hwt_obj_0
	.thumb
	.thumb_func
	.type task_wlogo_hwt_obj_0, %function
task_wlogo_hwt_obj_0: @ 080B4CD8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	movs r0, #0x4A
	adds r0, r0, r7
	mov r8, r0
	movs r6, #0x00
	strb r1, [r0, #0x00]
	ldr r0, _080B4DB8 @ =0x0961B072
	movs r1, #0xF2
	lsls r1, r1, #0x04
	bl LoadObjTiles
	str r0, [r7, #0x00]
	ldr r0, _080B4DBC @ =0x096FAD64
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x04]
	adds r4, r7, #0x0
	adds r4, #0x0C
	ldr r1, _080B4DC0 @ =0x09EF356C
	ldr r2, _080B4DC4 @ =0x09EF3548
	adds r0, r4, #0x0
	bl AnimInit
	ldr r5, _080B4DC8 @ =0x096194D0
	mov r1, r8
	ldrb r0, [r1, #0x00]
	lsls r0, r0, #0x04
	adds r0, r0, r5
	ldrb r1, [r0, #0x0C]
	adds r0, r4, #0x0
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x08]
	mov r1, r8
	ldrb r0, [r1, #0x00]
	lsls r0, r0, #0x04
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x24]
	ldrb r0, [r1, #0x00]
	lsls r0, r0, #0x04
	adds r1, r5, #0x4
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x28]
	ldr r2, _080B4DCC @ =0x09619530
	mov r0, r8
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r1, r2, #0x4
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x2C]
	mov r0, r8
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r1, r2, #0x0
	adds r1, #0x08
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x30]
	mov r0, r8
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r1, r2, #0x0
	adds r1, #0x0C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x34]
	mov r0, r8
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r1, r2, #0x0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x38]
	mov r1, r8
	ldrb r0, [r1, #0x00]
	lsls r0, r0, #0x04
	adds r5, #0x08
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x44]
	movs r1, #0x00
	strh r6, [r7, #0x3C]
	strh r6, [r7, #0x3E]
	adds r0, r7, #0x0
	adds r0, #0x40
	strb r1, [r0, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B4DB8: .4byte 0x0961B072
_080B4DBC: .4byte 0x096FAD64
_080B4DC0: .4byte 0x09EF356C
_080B4DC4: .4byte 0x09EF3548
_080B4DC8: .4byte 0x096194D0
_080B4DCC: .4byte 0x09619530
.syntax divided
