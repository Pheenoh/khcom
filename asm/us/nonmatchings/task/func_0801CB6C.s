.syntax unified
	.align 2, 0
	.global func_0801CB6C
	.thumb
	.thumb_func
	.type func_0801CB6C, %function
func_0801CB6C: @ 0801CB6C
	push {r4, r5, lr}
	subs r5, r2, r0
	subs r4, r3, r1
	movs r0, #0x00
	cmp r5, #0x00
	bne _0801CB7C
	cmp r4, #0x00
	beq _0801CC78
_0801CB7C:
	cmp r5, #0x00
	ble _0801CBE0
	cmp r4, #0x00
	bge _0801CBB0
	negs r4, r4
	cmp r5, r4
	bgt _0801CB9A
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r4, #0x0
	bl __divsi3
	muls r0, r5
	asrs r0, r0, #0x10
	b _0801CC48
_0801CB9A:
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r5, #0x0
	bl __divsi3
	adds r1, r0, #0x0
	muls r1, r4
	asrs r1, r1, #0x10
	movs r0, #0x40
	subs r0, r0, r1
	b _0801CC48
_0801CBB0:
	cmp r4, #0x00
	ble _0801CBE0
	cmp r5, r4
	bgt _0801CBCE
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r4, #0x0
	bl __divsi3
	adds r1, r0, #0x0
	muls r1, r5
	asrs r1, r1, #0x10
	movs r0, #0x7F
	subs r0, r0, r1
	b _0801CC48
_0801CBCE:
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r5, #0x0
	bl __divsi3
	muls r0, r4
	asrs r0, r0, #0x10
	adds r0, #0x3F
	b _0801CC48
_0801CBE0:
	cmp r5, #0x00
	bge _0801CC4E
	cmp r4, #0x00
	ble _0801CC1A
	negs r5, r5
	cmp r5, r4
	bgt _0801CC00
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r4, #0x0
	bl __divsi3
	muls r0, r5
	asrs r0, r0, #0x10
	subs r0, #0x80
	b _0801CC48
_0801CC00:
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r5, #0x0
	bl __divsi3
	adds r1, r0, #0x0
	muls r1, r4
	asrs r1, r1, #0x10
	movs r2, #0x40
	negs r2, r2
	adds r0, r2, #0x0
	subs r0, r0, r1
	b _0801CC48
_0801CC1A:
	cmp r4, #0x00
	bge _0801CC4E
	negs r5, r5
	negs r4, r4
	cmp r5, r4
	bgt _0801CC38
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r4, #0x0
	bl __divsi3
	muls r0, r5
	asrs r0, r0, #0x10
	mvns r0, r0
	b _0801CC48
_0801CC38:
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r5, #0x0
	bl __divsi3
	muls r0, r4
	asrs r0, r0, #0x10
	subs r0, #0x41
_0801CC48:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801CC78
_0801CC4E:
	cmp r5, #0x00
	bne _0801CC62
	cmp r4, #0x00
	bge _0801CC5A
	movs r0, #0x00
	b _0801CC78
_0801CC5A:
	cmp r4, #0x00
	ble _0801CC62
	movs r0, #0x80
	b _0801CC78
_0801CC62:
	cmp r5, #0x00
	bge _0801CC6E
	cmp r4, #0x00
	bne _0801CC6E
	movs r0, #0xC0
	b _0801CC78
_0801CC6E:
	cmp r5, #0x00
	ble _0801CC78
	cmp r4, #0x00
	bne _0801CC78
	movs r0, #0x40
_0801CC78:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
