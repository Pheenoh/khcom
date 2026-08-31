.syntax unified
	.align 2, 0
	.global task_sroll_b_logo_0
	.thumb
	.thumb_func
	.type task_sroll_b_logo_0, %function
task_sroll_b_logo_0: @ 08114C24
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r4, r1, #0x0
	ldr r0, [r4, #0x00]
	str r0, [r6, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [r6, #0x04]
	ldr r0, [r4, #0x08]
	str r0, [r6, #0x08]
	ldr r0, [r4, #0x0C]
	str r0, [r6, #0x0C]
	ldr r0, _08114C88 @ =0x09C5CC7C
	movs r1, #0xBC
	lsls r1, r1, #0x04
	bl LoadObjTiles
	str r0, [r6, #0x10]
	ldr r0, _08114C8C @ =0x09D6BE34
	movs r1, #0x40
	bl LoadObjPalette
	str r0, [r6, #0x14]
	adds r5, r6, #0x0
	adds r5, #0x18
	ldr r1, _08114C90 @ =0x09EFAF6C
	ldr r2, _08114C94 @ =0x09EFAF60
	adds r0, r5, #0x0
	bl AnimInit
	ldrh r1, [r4, #0x10]
	adds r0, r5, #0x0
	movs r2, #0x00
	bl AnimStart
	movs r4, #0x00
_08114C6A:
	ldr r0, [r6, #0x14]
	ldrh r0, [r0, #0x06]
	adds r0, r0, r4
	movs r1, #0x0F
	ands r0, r1
	adds r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	adds r4, #0x01
	cmp r4, #0x01
	bls _08114C6A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08114C88: .4byte 0x09C5CC7C
_08114C8C: .4byte 0x09D6BE34
_08114C90: .4byte 0x09EFAF6C
_08114C94: .4byte 0x09EFAF60
.syntax divided
