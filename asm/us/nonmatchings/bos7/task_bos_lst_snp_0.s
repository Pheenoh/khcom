.syntax unified
	.align 2, 0
	.global task_bos_lst_snp_0
	.thumb
	.thumb_func
	.type task_bos_lst_snp_0, %function
task_bos_lst_snp_0: @ 08112420
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	movs r0, #0x00
	strb r0, [r4, #0x00]
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x04]
	ldr r0, [r5, #0x04]
	str r0, [r4, #0x08]
	ldr r0, [r5, #0x08]
	str r0, [r4, #0x0C]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081124A8 @ =0x00000181
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x80
	movs r2, #0x0C
	ldsh r1, [r5, r2]
	muls r0, r1
	str r0, [r4, #0x10]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081124AC @ =0x00000201
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x03
	adds r0, r0, r1
	negs r0, r0
	str r0, [r4, #0x14]
	ldr r0, _081124B0 @ =0x09CD0E34
	movs r1, #0x90
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r4, #0x18]
	ldr r0, _081124B4 @ =0x09D69594
	movs r1, #0x60
	bl LoadObjPalette
	str r0, [r4, #0x1C]
	ldr r0, _081124B8 @ =0x000002C3
	bl m4aSongNumStart
	adds r4, #0x20
	ldr r1, _081124BC @ =0x09EFBF60
	ldr r2, _081124C0 @ =0x09EFBF5C
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081124A8: .4byte 0x00000181
_081124AC: .4byte 0x00000201
_081124B0: .4byte 0x09CD0E34
_081124B4: .4byte 0x09D69594
_081124B8: .4byte 0x000002C3
_081124BC: .4byte 0x09EFBF60
_081124C0: .4byte 0x09EFBF5C
.syntax divided
