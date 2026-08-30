.syntax unified
	.align 2, 0
	.global func_080D422C
	.thumb
	.thumb_func
	.type func_080D422C, %function
func_080D422C: @ 080D422C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r0, #0x00
	mov r10, r0
	ldr r2, _080D4290 @ =0x096FDC30
	mov r9, r2
_080D4240:
	mov r3, r10
	lsls r7, r3, #0x02
	mov r0, r9
	ldrh r1, [r0, #0x00]
	add r1, r8
	lsls r1, r1, #0x10
	mov r2, r8
	lsrs r0, r2, #0x10
	mov r3, r9
	ldrh r3, [r3, #0x02]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r5, r1, #0x10
	orrs r5, r0
	adds r0, r5, #0x0
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r6, r4, #0x0
	cmp r4, #0xFF
	beq _080D42B4
	mov r0, r8
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bne _080D4298
	ldr r0, _080D4294 @ =0x096FDC40
	adds r0, r7, r0
	ldrb r1, [r0, #0x00]
	adds r0, r4, #0x0
	bl func_080D3AB8
	b _080D42A4
_080D4290: .4byte 0x096FDC30
_080D4294: .4byte 0x096FDC40
_080D4298:
	ldr r0, _080D42B0 @ =0x096FDC40
	adds r0, r7, r0
	ldrb r1, [r0, #0x00]
	adds r0, r6, #0x0
	bl func_080D3A70
_080D42A4:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x00
	beq _080D42B4
	movs r0, #0x01
	b _080D42C4
_080D42B0: .4byte 0x096FDC40
_080D42B4:
	movs r0, #0x04
	add r9, r0
	movs r2, #0x01
	add r10, r2
	mov r3, r10
	cmp r3, #0x03
	ble _080D4240
	movs r0, #0x00
_080D42C4:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
