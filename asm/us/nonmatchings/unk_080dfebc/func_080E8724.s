.syntax unified
	.align 2, 0
	.global func_080E8724
	.thumb
	.thumb_func
	.type func_080E8724, %function
func_080E8724: @ 080E8724
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r5, r2, #0x0
	mov r9, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x000]
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080E8754
_080E8752:
	adds r5, #0x08
_080E8754:
	ldrb r1, [r5, #0x00]
	cmp r0, r1
	bcs _080E8752
	movs r7, #0x00
	ldrb r0, [r5, #0x03]
	cmp r7, r0
	bge _080E87DC
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	mov r10, r0
_080E8768:
	movs r3, #0x00
	adds r1, r7, #0x1
	mov r8, r1
	ldrb r0, [r5, #0x04]
	cmp r3, r0
	bge _080E87D4
	ldr r1, [sp, #0x000]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r7
	lsls r6, r0, #0x10
	mov r4, r10
_080E8780:
	ldrb r0, [r5, #0x05]
	cmp r0, #0x01
	beq _080E8790
	cmp r0, #0x01
	ble _080E87A2
	cmp r0, #0x02
	beq _080E879C
	b _080E87A2
_080E8790:
	mvns r1, r7
	ldrb r0, [r5, #0x03]
	adds r1, r1, r0
	adds r1, r4, r1
	lsls r1, r1, #0x10
	b _080E87A4
_080E879C:
	adds r1, r4, r7
	lsls r1, r1, #0x10
	b _080E87A4
_080E87A2:
	lsls r1, r4, #0x10
_080E87A4:
	asrs r1, r1, #0x10
	asrs r0, r6, #0x10
	str r3, [sp, #0x004]
	bl func_080E548C
	adds r2, r0, #0x0
	ldr r3, [sp, #0x004]
	ldrb r0, [r5, #0x02]
	adds r0, r0, r3
	lsls r0, r0, #0x06
	ldrb r1, [r5, #0x01]
	adds r1, r1, r7
	lsls r1, r1, #0x02
	adds r0, r0, r1
	movs r1, #0x32
	strb r1, [r2, #0x04]
	lsls r0, r0, #0x01
	add r0, r9
	str r0, [r2, #0x18]
	adds r4, #0x01
	adds r3, #0x01
	ldrb r1, [r5, #0x04]
	cmp r3, r1
	blt _080E8780
_080E87D4:
	mov r7, r8
	ldrb r0, [r5, #0x03]
	cmp r7, r0
	blt _080E8768
_080E87DC:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
