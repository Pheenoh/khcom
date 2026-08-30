.syntax unified
	.align 2, 0
	.global func_0811D684
	.thumb
	.thumb_func
	.type func_0811D684, %function
func_0811D684: @ 0811D684
	movs r3, #0x01
	cmp r1, #0x00
	beq _0811D748
	bpl _0811D68E
	negs r1, r1
_0811D68E:
	push {r4}
	push {r0}
	cmp r0, #0x00
	bpl _0811D698
	negs r0, r0
_0811D698:
	cmp r0, r1
	bcc _0811D73C
	movs r4, #0x01
	lsls r4, r4, #0x1C
_0811D6A0:
	cmp r1, r4
	bcs _0811D6AE
	cmp r1, r0
	bcs _0811D6AE
	lsls r1, r1, #0x04
	lsls r3, r3, #0x04
	b _0811D6A0
_0811D6AE:
	lsls r4, r4, #0x03
_0811D6B0:
	cmp r1, r4
	bcs _0811D6BE
	cmp r1, r0
	bcs _0811D6BE
	lsls r1, r1, #0x01
	lsls r3, r3, #0x01
	b _0811D6B0
_0811D6BE:
	movs r2, #0x00
	cmp r0, r1
	bcc _0811D6C6
	subs r0, r0, r1
_0811D6C6:
	lsrs r4, r1, #0x01
	cmp r0, r4
	bcc _0811D6D8
	subs r0, r0, r4
	mov r12, r3
	movs r4, #0x01
	rors r3, r4
	orrs r2, r3
	mov r3, r12
_0811D6D8:
	lsrs r4, r1, #0x02
	cmp r0, r4
	bcc _0811D6EA
	subs r0, r0, r4
	mov r12, r3
	movs r4, #0x02
	rors r3, r4
	orrs r2, r3
	mov r3, r12
_0811D6EA:
	lsrs r4, r1, #0x03
	cmp r0, r4
	bcc _0811D6FC
	subs r0, r0, r4
	mov r12, r3
	movs r4, #0x03
	rors r3, r4
	orrs r2, r3
	mov r3, r12
_0811D6FC:
	mov r12, r3
	cmp r0, #0x00
	beq _0811D70A
	lsrs r3, r3, #0x04
	beq _0811D70A
	lsrs r1, r1, #0x04
	b _0811D6BE
_0811D70A:
	movs r4, #0x0E
	lsls r4, r4, #0x1C
	ands r2, r4
	beq _0811D73C
	mov r3, r12
	movs r4, #0x03
	rors r3, r4
	tst r2, r3
	beq _0811D720
	lsrs r4, r1, #0x03
	adds r0, r0, r4
_0811D720:
	mov r3, r12
	movs r4, #0x02
	rors r3, r4
	tst r2, r3
	beq _0811D72E
	lsrs r4, r1, #0x02
	adds r0, r0, r4
_0811D72E:
	mov r3, r12
	movs r4, #0x01
	rors r3, r4
	tst r2, r3
	beq _0811D73C
	lsrs r4, r1, #0x01
	adds r0, r0, r4
_0811D73C:
	pop {r4}
	cmp r4, #0x00
	bpl _0811D744
	negs r0, r0
_0811D744:
	pop {r4}
	mov pc, lr
_0811D748:
	push {lr}
	bl func_0811D680
	movs r0, #0x00
	pop {pc}
	.byte 0x00, 0x00
.syntax divided
