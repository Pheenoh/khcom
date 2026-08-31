.syntax unified
	.align 2, 0
	.global task_ms_shop_hosi_0
	.thumb
	.thumb_func
	.type task_ms_shop_hosi_0, %function
task_ms_shop_hosi_0: @ 0810951C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	movs r1, #0x00
	ldsh r0, [r5, r1]
	lsls r0, r0, #0x08
	str r0, [r4, #0x00]
	movs r2, #0x02
	ldsh r0, [r5, r2]
	lsls r0, r0, #0x08
	str r0, [r4, #0x04]
	ldr r2, _08109588 @ =0x08121400
	ldrb r0, [r5, #0x08]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r1, [r5, #0x0C]
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r4, #0x08]
	ldrb r0, [r5, #0x08]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r0, [r0, r2]
	negs r0, r0
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r4, #0x0C]
	movs r0, #0x00
	strh r0, [r4, #0x10]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x07
	ands r0, r1
	adds r0, #0x04
	strh r0, [r4, #0x14]
	strh r0, [r4, #0x12]
	ldr r0, [r5, #0x04]
	str r0, [r4, #0x18]
	ldr r0, _0810958C @ =0x099A6962
	movs r1, #0xF0
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r4, #0x1C]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08109588: .4byte 0x08121400
_0810958C: .4byte 0x099A6962
.syntax divided
