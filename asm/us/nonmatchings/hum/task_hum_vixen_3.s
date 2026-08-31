.syntax unified
	.align 2, 0
	.global task_hum_vixen_3
	.thumb
	.thumb_func
	.type task_hum_vixen_3, %function
task_hum_vixen_3: @ 08055464
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _0805549C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _08055484
	ldr r0, _080554A0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
_08055484:
	adds r0, r4, #0x0
	bl func_0800E380
	movs r1, #0xD2
	lsls r1, r1, #0x01
	adds r0, r4, r1
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805549C: .4byte 0x02039BB0
_080554A0: .4byte 0x02039B84
.syntax divided
