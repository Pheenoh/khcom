.syntax unified
	.align 2, 0
	.global task_bos_pc_acd_0
	.thumb
	.thumb_func
	.type task_bos_pc_acd_0, %function
task_bos_pc_acd_0: @ 0810BF2C
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	movs r6, #0x00
	str r6, [r5, #0x00]
	movs r0, #0xC0
	lsls r0, r0, #0x02
	ldr r1, _0810BF7C @ =0x09C489E4
	bl AllocObjTiles
	str r0, [r5, #0x04]
	ldr r0, _0810BF80 @ =0x09D693D4
	movs r1, #0x60
	bl LoadObjPalette
	str r0, [r5, #0x08]
	movs r0, #0x01
	negs r0, r0
	str r0, [r5, #0x0C]
	str r0, [r5, #0x10]
	str r0, [r5, #0x14]
	str r4, [r5, #0x1C]
	adds r4, r5, #0x0
	adds r4, #0x20
	ldr r1, _0810BF84 @ =0x09EFABA4
	ldr r2, _0810BF88 @ =0x09EFAB68
	adds r0, r4, #0x0
	bl AnimInit
	ldr r0, [r5, #0x1C]
	ldrb r0, [r0, #0x05]
	cmp r0, #0x01
	bne _0810BF8C
	strb r0, [r5, #0x18]
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl AnimStart
	b _0810BF98
_0810BF7C: .4byte 0x09C489E4
_0810BF80: .4byte 0x09D693D4
_0810BF84: .4byte 0x09EFABA4
_0810BF88: .4byte 0x09EFAB68
_0810BF8C:
	strb r6, [r5, #0x18]
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
_0810BF98:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
