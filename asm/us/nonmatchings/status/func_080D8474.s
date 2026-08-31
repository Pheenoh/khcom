.syntax unified
	.align 2, 0
	.global func_080D8474
	.thumb
	.thumb_func
	.type func_080D8474, %function
func_080D8474: @ 080D8474
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r5, #0x00
	ldr r6, _080D8554 @ =0x02034F04
_080D8484:
	ldr r0, [r6, #0x00]
	lsls r4, r5, #0x02
	movs r1, #0x92
	lsls r1, r1, #0x03
	adds r0, r0, r1
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D84A8
	bl ReleaseObjTiles
	ldr r0, [r6, #0x00]
	movs r1, #0x92
	lsls r1, r1, #0x03
	adds r0, r0, r1
	adds r0, r0, r4
	movs r1, #0x00
	str r1, [r0, #0x00]
_080D84A8:
	adds r5, #0x01
	cmp r5, #0x07
	ble _080D8484
	ldr r3, _080D8554 @ =0x02034F04
	ldr r2, [r3, #0x00]
	ldr r6, _080D8558 @ =0x000004C4
	adds r0, r2, r6
	strh r7, [r0, #0x00]
	movs r5, #0x00
	movs r4, #0x98
	lsls r4, r4, #0x03
	adds r0, r2, r4
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r2, r2, r0
	movs r0, #0x90
	lsls r0, r0, #0x01
	adds r2, r2, r0
	ldrh r0, [r2, #0x00]
	subs r0, r0, r7
	cmp r5, r0
	bge _080D8546
	mov r8, r3
	mov r9, r4
	lsls r4, r7, #0x02
_080D84E4:
	mov r1, r8
	ldr r2, [r1, #0x00]
	mov r6, r9
	adds r0, r2, r6
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r4, r0
	adds r2, r2, r0
	ldr r0, [r2, #0x00]
	bl _080D85F8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_080D85C0
	mov r1, r8
	ldr r3, [r1, #0x00]
	lsls r2, r5, #0x02
	movs r6, #0x92
	lsls r6, r6, #0x03
	adds r1, r3, r6
	adds r1, r1, r2
	str r0, [r1, #0x00]
	adds r4, #0x04
	adds r5, #0x01
	mov r1, r9
	adds r0, r3, r1
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r3, r3, r0
	movs r6, #0x90
	lsls r6, r6, #0x01
	adds r3, r3, r6
	ldrh r0, [r3, #0x00]
	subs r0, r0, r7
	cmp r5, r0
	bge _080D8546
	cmp r5, #0x07
	ble _080D84E4
_080D8546:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D8554: .4byte 0x02034F04
_080D8558: .4byte 0x000004C4
.syntax divided
