.syntax unified
	.align 2, 0
	.global func_0811D5EC
	.thumb
	.thumb_func
	.type func_0811D5EC, %function
func_0811D5EC: @ 0811D5EC
	cmp r1, #0x00
	beq _0811D674
	push {r4}
	adds r4, r0, #0x0
	eors r4, r1
	mov r12, r4
	movs r3, #0x01
	movs r2, #0x00
	cmp r1, #0x00
	bpl _0811D602
	negs r1, r1
_0811D602:
	cmp r0, #0x00
	bpl _0811D608
	negs r0, r0
_0811D608:
	cmp r0, r1
	bcc _0811D666
	movs r4, #0x01
	lsls r4, r4, #0x1C
_0811D610:
	cmp r1, r4
	bcs _0811D61E
	cmp r1, r0
	bcs _0811D61E
	lsls r1, r1, #0x04
	lsls r3, r3, #0x04
	b _0811D610
_0811D61E:
	lsls r4, r4, #0x03
_0811D620:
	cmp r1, r4
	bcs _0811D62E
	cmp r1, r0
	bcs _0811D62E
	lsls r1, r1, #0x01
	lsls r3, r3, #0x01
	b _0811D620
_0811D62E:
	cmp r0, r1
	bcc _0811D636
	subs r0, r0, r1
	orrs r2, r3
_0811D636:
	lsrs r4, r1, #0x01
	cmp r0, r4
	bcc _0811D642
	subs r0, r0, r4
	lsrs r4, r3, #0x01
	orrs r2, r4
_0811D642:
	lsrs r4, r1, #0x02
	cmp r0, r4
	bcc _0811D64E
	subs r0, r0, r4
	lsrs r4, r3, #0x02
	orrs r2, r4
_0811D64E:
	lsrs r4, r1, #0x03
	cmp r0, r4
	bcc _0811D65A
	subs r0, r0, r4
	lsrs r4, r3, #0x03
	orrs r2, r4
_0811D65A:
	cmp r0, #0x00
	beq _0811D666
	lsrs r3, r3, #0x04
	beq _0811D666
	lsrs r1, r1, #0x04
	b _0811D62E
_0811D666:
	adds r0, r2, #0x0
	mov r4, r12
	cmp r4, #0x00
	bpl _0811D670
	negs r0, r0
_0811D670:
	pop {r4}
	mov pc, lr
_0811D674:
	push {lr}
	bl func_0811D680
	movs r0, #0x00
	pop {pc}
	.byte 0x00, 0x00
.syntax divided
