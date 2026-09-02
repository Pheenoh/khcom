.syntax unified
	.align 2, 0
	.global func_0808B3DC
	.thumb
	.thumb_func
	.type func_0808B3DC, %function
func_0808B3DC: @ 0808B3DC
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r7, r0, #0x0
	lsls r1, r1, #0x18
	cmp r1, #0x00
	beq _0808B3EA
	b _0808B5B4
_0808B3EA:
	movs r1, #0x8C
	lsls r1, r1, #0x04
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _0808B498
	cmp r0, #0x01
	bgt _0808B400
	cmp r0, #0x00
	beq _0808B408
	b _0808B656
_0808B400:
	cmp r0, #0x02
	bne _0808B406
	b _0808B524
_0808B406:
	b _0808B656
_0808B408:
	ldr r2, _0808B474 @ =0x00000888
	adds r0, r7, r2
	movs r3, #0x00
	ldsh r0, [r0, r3]
	ldr r4, _0808B478 @ =0x0000088E
	adds r1, r7, r4
	movs r5, #0x00
	ldsh r1, [r1, r5]
	adds r2, r7, #0x0
	adds r2, #0x38
	ldr r3, [r7, #0x14]
	movs r5, #0x14
	str r5, [sp, #0x000]
	ldr r6, _0808B47C @ =0x000008C2
	adds r4, r7, r6
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
	ldr r1, _0808B480 @ =0x0000088A
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x89
	lsls r3, r3, #0x04
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0x78
	ldr r3, _0808B484 @ =0x000004C4
	adds r6, r7, r3
	ldr r3, [r6, #0x00]
	str r5, [sp, #0x000]
	ldr r4, _0808B488 @ =0x000008C3
	ldrb r4, [r4, r7]
	str r4, [sp, #0x004]
	bl func_080664D8
	ldr r1, _0808B48C @ =0x0000088C
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _0808B490 @ =0x00000892
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0xB8
	ldr r3, [r6, #0x00]
	str r5, [sp, #0x000]
	ldr r5, _0808B494 @ =0x000008C4
	b _0808B61A
	.byte 0x00, 0x00
_0808B474: .4byte 0x00000888
_0808B478: .4byte 0x0000088E
_0808B47C: .4byte 0x000008C2
_0808B480: .4byte 0x0000088A
_0808B484: .4byte 0x000004C4
_0808B488: .4byte 0x000008C3
_0808B48C: .4byte 0x0000088C
_0808B490: .4byte 0x00000892
_0808B494: .4byte 0x000008C4
_0808B498:
	ldr r6, _0808B500 @ =0x00000888
	adds r0, r7, r6
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, _0808B504 @ =0x0000088E
	adds r1, r7, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r2, r7, #0x0
	adds r2, #0x38
	ldr r4, _0808B508 @ =0x000004C4
	adds r6, r7, r4
	ldr r3, [r6, #0x00]
	movs r5, #0x14
	str r5, [sp, #0x000]
	ldr r4, _0808B50C @ =0x000008C2
	ldrb r4, [r4, r7]
	str r4, [sp, #0x004]
	bl func_080664D8
	ldr r1, _0808B510 @ =0x0000088A
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x89
	lsls r3, r3, #0x04
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0x78
	ldr r3, [r7, #0x14]
	str r5, [sp, #0x000]
	ldr r4, _0808B514 @ =0x000008C3
	ldrb r4, [r4, r7]
	str r4, [sp, #0x004]
	bl func_080664D8
	ldr r1, _0808B518 @ =0x0000088C
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _0808B51C @ =0x00000892
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0xB8
	ldr r3, [r6, #0x00]
	str r5, [sp, #0x000]
	ldr r5, _0808B520 @ =0x000008C4
	b _0808B61A
_0808B500: .4byte 0x00000888
_0808B504: .4byte 0x0000088E
_0808B508: .4byte 0x000004C4
_0808B50C: .4byte 0x000008C2
_0808B510: .4byte 0x0000088A
_0808B514: .4byte 0x000008C3
_0808B518: .4byte 0x0000088C
_0808B51C: .4byte 0x00000892
_0808B520: .4byte 0x000008C4
_0808B524:
	ldr r6, _0808B590 @ =0x00000888
	adds r0, r7, r6
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, _0808B594 @ =0x0000088E
	adds r1, r7, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r2, r7, #0x0
	adds r2, #0x38
	ldr r4, _0808B598 @ =0x000004C4
	adds r6, r7, r4
	ldr r3, [r6, #0x00]
	movs r5, #0x14
	str r5, [sp, #0x000]
	ldr r4, _0808B59C @ =0x000008C2
	ldrb r4, [r4, r7]
	str r4, [sp, #0x004]
	bl func_080664D8
	ldr r1, _0808B5A0 @ =0x0000088A
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x89
	lsls r3, r3, #0x04
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0x78
	ldr r3, [r6, #0x00]
	str r5, [sp, #0x000]
	ldr r6, _0808B5A4 @ =0x000008C3
	adds r4, r7, r6
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
	ldr r1, _0808B5A8 @ =0x0000088C
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _0808B5AC @ =0x00000892
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0xB8
	ldr r3, [r7, #0x14]
	str r5, [sp, #0x000]
	ldr r5, _0808B5B0 @ =0x000008C4
	b _0808B61A
	.byte 0x00, 0x00
_0808B590: .4byte 0x00000888
_0808B594: .4byte 0x0000088E
_0808B598: .4byte 0x000004C4
_0808B59C: .4byte 0x000008C2
_0808B5A0: .4byte 0x0000088A
_0808B5A4: .4byte 0x000008C3
_0808B5A8: .4byte 0x0000088C
_0808B5AC: .4byte 0x00000892
_0808B5B0: .4byte 0x000008C4
_0808B5B4:
	movs r6, #0x8C
	lsls r6, r6, #0x04
	adds r0, r7, r6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _0808B5FC
	cmp r0, #0x01
	bgt _0808B5CA
	cmp r0, #0x00
	beq _0808B5D0
	b _0808B656
_0808B5CA:
	cmp r0, #0x02
	beq _0808B630
	b _0808B656
_0808B5D0:
	ldr r1, _0808B5F0 @ =0x00000888
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _0808B5F4 @ =0x0000088E
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0x38
	ldr r3, [r7, #0x14]
	movs r4, #0x14
	str r4, [sp, #0x000]
	ldr r5, _0808B5F8 @ =0x000008C2
	b _0808B61A
	.byte 0x00, 0x00
_0808B5F0: .4byte 0x00000888
_0808B5F4: .4byte 0x0000088E
_0808B5F8: .4byte 0x000008C2
_0808B5FC:
	ldr r6, _0808B628 @ =0x0000088A
	adds r0, r7, r6
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x89
	lsls r2, r2, #0x04
	adds r1, r7, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r2, r7, #0x0
	adds r2, #0x78
	ldr r3, [r7, #0x14]
	movs r4, #0x14
	str r4, [sp, #0x000]
	ldr r5, _0808B62C @ =0x000008C3
_0808B61A:
	adds r4, r7, r5
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
	b _0808B656
	.byte 0x00, 0x00
_0808B628: .4byte 0x0000088A
_0808B62C: .4byte 0x000008C3
_0808B630:
	ldr r6, _0808B660 @ =0x0000088C
	adds r0, r7, r6
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, _0808B664 @ =0x00000892
	adds r1, r7, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r2, r7, #0x0
	adds r2, #0xB8
	ldr r3, [r7, #0x14]
	movs r4, #0x14
	str r4, [sp, #0x000]
	ldr r5, _0808B668 @ =0x000008C4
	adds r4, r7, r5
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
_0808B656:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0808B660: .4byte 0x0000088C
_0808B664: .4byte 0x00000892
_0808B668: .4byte 0x000008C4
.syntax divided
