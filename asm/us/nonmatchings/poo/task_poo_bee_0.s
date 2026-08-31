.syntax unified
	.align 2, 0
	.global task_poo_bee_0
	.thumb
	.thumb_func
	.type task_poo_bee_0, %function
task_poo_bee_0: @ 080D0A14
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0x0
	adds r1, r5, #0x0
	adds r1, #0xA4
	ldr r0, _080D0AC8 @ =0x0008DE00
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _080D0ACC @ =0x00046600
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _080D0AD0 @ =0xFFFFF600
	str r0, [r1, #0x00]
	adds r1, #0x04
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r7, #0x00
	ldr r0, _080D0AD4 @ =0x09EF6024
	mov r9, r0
	ldr r0, _080D0AD8 @ =0x09EF5FF8
	mov r10, r0
	ldr r6, _080D0ADC @ =0x096FD730
	adds r4, r5, #0x0
	adds r4, #0x24
	ldr r0, _080D0AE0 @ =0xFFFFFB00
	mov r8, r0
	movs r0, #0xA0
	lsls r0, r0, #0x03
	mov r12, r0
	adds r3, r5, #0x0
	adds r3, #0x28
_080D0A58:
	lsls r2, r7, #0x05
	mov r0, r8
	str r0, [r4, #0x00]
	mov r0, r12
	str r0, [r3, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x34
	adds r0, r0, r2
	ldr r1, [r6, #0x00]
	str r1, [r0, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x38
	adds r0, r0, r2
	ldr r1, [r6, #0x04]
	str r1, [r0, #0x00]
	adds r6, #0x08
	adds r4, #0x20
	adds r3, #0x20
	adds r7, #0x01
	cmp r7, #0x03
	ble _080D0A58
	adds r4, r5, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	mov r1, r9
	mov r2, r10
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r5, #0x08]
	movs r1, #0x00
	str r1, [r5, #0x04]
	ldr r0, _080D0AE4 @ =0x02034E2C
	str r1, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0xC6
	movs r0, #0x08
	strh r0, [r1, #0x00]
	adds r1, #0x02
	movs r0, #0x01
	strb r0, [r1, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D0AC8: .4byte 0x0008DE00
_080D0ACC: .4byte 0x00046600
_080D0AD0: .4byte 0xFFFFF600
_080D0AD4: .4byte 0x09EF6024
_080D0AD8: .4byte 0x09EF5FF8
_080D0ADC: .4byte 0x096FD730
_080D0AE0: .4byte 0xFFFFFB00
_080D0AE4: .4byte 0x02034E2C
.syntax divided
