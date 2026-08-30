.syntax unified
	.align 2, 0
	.global task_bos_md_hahen_0
	.thumb
	.thumb_func
	.type task_bos_md_hahen_0, %function
task_bos_md_hahen_0: @ 080FD824
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r6, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r6, #0x00]
	ldr r0, [r1, #0x04]
	str r0, [r6, #0x04]
	ldr r0, [r1, #0x08]
	str r0, [r6, #0x08]
	bl func_080065A4
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl func_080065A4
	ldr r5, _080FD8C0 @ =0x000001FF
	adds r1, r5, #0x0
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x01
	mov r8, r0
	add r1, r8
	ldr r2, _080FD8C4 @ =0x08121400
	adds r0, r4, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r3, #0x00
	ldsh r0, [r0, r3]
	negs r0, r0
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r6, #0x0C]
	lsls r4, r4, #0x01
	adds r4, r4, r2
	movs r2, #0x00
	ldsh r0, [r4, r2]
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r6, #0x10]
	bl func_080065A4
	ands r5, r0
	add r5, r8
	negs r5, r5
	str r5, [r6, #0x14]
	movs r0, #0x03
	strh r0, [r6, #0x24]
	ldr r0, _080FD8C8 @ =0x09A3C9BC
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x18]
	ldr r0, _080FD8CC @ =0x09999ED0
	movs r1, #0x90
	lsls r1, r1, #0x03
	bl func_080026A4
	str r0, [r6, #0x1C]
	bl func_080065A4
	ldr r2, _080FD8D0 @ =0x09EF9740
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	ands r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x20]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FD8C0: .4byte 0x000001FF
_080FD8C4: .4byte 0x08121400
_080FD8C8: .4byte 0x09A3C9BC
_080FD8CC: .4byte 0x09999ED0
_080FD8D0: .4byte 0x09EF9740
.syntax divided
