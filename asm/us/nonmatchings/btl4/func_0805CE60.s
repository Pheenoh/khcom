.syntax unified
	.align 2, 0
	.global func_0805CE60
	.thumb
	.thumb_func
	.type func_0805CE60, %function
func_0805CE60: @ 0805CE60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0x0
	ldr r5, _0805CF18 @ =0x00002710
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl _0811D754
	movs r1, #0x00
	bl _0805CDC8
	adds r4, r0, #0x0
	mov r0, r8
	str r4, [r0, #0x24]
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl func_0811D7CC
	adds r6, r0, #0x0
	negs r0, r4
	orrs r0, r4
	lsrs r7, r0, #0x1F
	movs r5, #0xFA
	lsls r5, r5, #0x02
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl _0811D754
	adds r1, r7, #0x0
	bl _0805CDC8
	adds r4, r0, #0x0
	mov r1, r8
	str r4, [r1, #0x28]
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl func_0811D7CC
	adds r6, r0, #0x0
	cmp r4, #0x00
	beq _0805CEB8
	movs r7, #0x01
_0805CEB8:
	adds r0, r6, #0x0
	movs r1, #0x64
	bl _0811D754
	adds r1, r7, #0x0
	bl _0805CDC8
	adds r4, r0, #0x0
	mov r0, r8
	str r4, [r0, #0x2C]
	adds r0, r6, #0x0
	movs r1, #0x64
	bl func_0811D7CC
	adds r6, r0, #0x0
	cmp r4, #0x00
	beq _0805CEDC
	movs r7, #0x01
_0805CEDC:
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl _0811D754
	adds r1, r7, #0x0
	bl _0805CDC8
	adds r4, r0, #0x0
	mov r1, r8
	str r4, [r1, #0x30]
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl func_0811D7CC
	adds r6, r0, #0x0
	ldr r1, _0805CF1C @ =0x09EE157C
	adds r0, r6, #0x4
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov r1, r8
	str r0, [r1, #0x34]
	ldr r0, _0805CF20 @ =0x08B25ED2
	str r0, [r1, #0x38]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805CF18: .4byte 0x00002710
_0805CF1C: .4byte 0x09EE157C
_0805CF20: .4byte 0x08B25ED2
.syntax divided
