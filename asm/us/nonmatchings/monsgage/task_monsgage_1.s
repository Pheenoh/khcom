.syntax unified
	.align 2, 0
	.global task_monsgage_1
	.thumb
	.thumb_func
	.type task_monsgage_1, %function
task_monsgage_1: @ 0805CA08
	push {r4, r5, r6, r7, lr}
	mov r12, r0
	ldr r1, _0805CA28 @ =0x02039B84
	ldr r6, [r1, #0x00]
	adds r0, r6, #0x0
	adds r0, #0xA0
	ldr r0, [r0, #0x00]
	adds r7, r1, #0x0
	cmp r0, #0x00
	bne _0805CA1E
	b _0805CBD0
_0805CA1E:
	cmp r0, #0x04
	bne _0805CA2C
	movs r0, #0x00
	b _0805CBD2
	.byte 0x00, 0x00
_0805CA28: .4byte 0x02039B84
_0805CA2C:
	mov r0, r12
	ldr r2, [r0, #0x20]
	cmp r2, #0x01
	beq _0805CA78
	cmp r2, #0x01
	bcc _0805CA3E
	cmp r2, #0x02
	beq _0805CB24
	b _0805CBC0
_0805CA3E:
	mov r1, r12
	movs r2, #0x1C
	ldsh r0, [r1, r2]
	cmp r0, #0x00
	bne _0805CA56
	mov r0, r12
	adds r0, #0x24
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _0805CA6C @ =0x08B2557C
	mov r3, r12
	str r0, [r3, #0x18]
_0805CA56:
	mov r0, r12
	ldrh r1, [r0, #0x1C]
	movs r2, #0x1C
	ldsh r0, [r0, r2]
	cmp r0, #0x78
	ble _0805CA70
	movs r0, #0x01
	mov r3, r12
	str r0, [r3, #0x20]
	movs r0, #0x00
	b _0805CBBE
_0805CA6C: .4byte 0x08B2557C
_0805CA70:
	adds r0, r1, #0x1
	mov r1, r12
	strh r0, [r1, #0x1C]
	b _0805CBC0
_0805CA78:
	mov r3, r12
	movs r1, #0x1C
	ldsh r0, [r3, r1]
	cmp r0, #0x00
	bne _0805CA86
	ldr r0, _0805CAAC @ =0x08B25586
	str r0, [r3, #0x18]
_0805CA86:
	mov r3, r12
	movs r0, #0x1C
	ldsh r1, [r3, r0]
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _0805CA94
	adds r0, r1, #0x7
_0805CA94:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	bgt _0805CAB0
	mov r0, r12
	adds r0, #0x24
	strb r2, [r0, #0x00]
	b _0805CAB8
	.byte 0x00, 0x00
_0805CAAC: .4byte 0x08B25586
_0805CAB0:
	mov r1, r12
	adds r1, #0x24
	movs r0, #0x00
	strb r0, [r1, #0x00]
_0805CAB8:
	mov r2, r12
	ldrh r1, [r2, #0x1C]
	movs r0, #0x03
	ands r1, r0
	cmp r1, #0x00
	bne _0805CAD0
	ldr r0, [r2, #0x0C]
	subs r0, #0x01
	str r0, [r2, #0x0C]
	cmp r0, #0x00
	bge _0805CAD0
	str r1, [r2, #0x0C]
_0805CAD0:
	ldr r6, [r7, #0x00]
	ldr r3, [r6, #0x68]
	ldr r4, [r6, #0x6C]
	movs r0, #0x80
	lsls r0, r0, #0x09
	movs r5, #0x00
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0805CB1A
	ldr r0, _0805CB08 @ =0xFFFEFFFF
	adds r1, r3, #0x0
	ands r1, r0
	adds r2, r4, #0x0
	str r1, [r6, #0x68]
	str r2, [r6, #0x6C]
	mov r3, r12
	strh r5, [r3, #0x1C]
	ldr r0, [r3, #0x0C]
	adds r0, #0x19
	str r0, [r3, #0x0C]
	cmp r0, #0xFF
	bgt _0805CB0C
	str r5, [r3, #0x20]
	b _0805CBC0
_0805CB08: .4byte 0xFFFEFFFF
_0805CB0C:
	movs r0, #0x80
	lsls r0, r0, #0x01
	mov r1, r12
	str r0, [r1, #0x0C]
	movs r0, #0x02
	str r0, [r1, #0x20]
	b _0805CBC0
_0805CB1A:
	mov r2, r12
	ldrh r0, [r2, #0x1C]
	adds r0, #0x01
	strh r0, [r2, #0x1C]
	b _0805CBC0
_0805CB24:
	mov r3, r12
	movs r1, #0x1C
	ldsh r0, [r3, r1]
	cmp r0, #0x00
	bne _0805CB4E
	ldr r0, _0805CB74 @ =0x08B25590
	str r0, [r3, #0x18]
	ldr r0, _0805CB78 @ =0x08B2559A
	str r0, [r3, #0x14]
	ldr r2, [r6, #0x68]
	ldr r3, [r6, #0x6C]
	ldr r0, _0805CB7C @ =0x00000000
	ldr r1, _0805CB80 @ =0x01000000
	orrs r3, r1
	ldr r4, _0805CB84 @ =0x00100000
	ldr r5, _0805CB88 @ =0x00000000
	adds r0, r2, #0x0
	orrs r0, r4
	adds r1, r3, #0x0
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
_0805CB4E:
	mov r2, r12
	movs r3, #0x1C
	ldsh r1, [r2, r3]
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _0805CB5C
	adds r0, r1, #0x7
_0805CB5C:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	bgt _0805CB8C
	mov r1, r12
	adds r1, #0x24
	movs r0, #0x01
	b _0805CB92
	.byte 0x00, 0x00
_0805CB74: .4byte 0x08B25590
_0805CB78: .4byte 0x08B2559A
_0805CB7C: .4byte 0x00000000
_0805CB80: .4byte 0x01000000
_0805CB84: .4byte 0x00100000
_0805CB88: .4byte 0x00000000
_0805CB8C:
	mov r1, r12
	adds r1, #0x24
	movs r0, #0x00
_0805CB92:
	strb r0, [r1, #0x00]
	mov r1, r12
	movs r2, #0x1C
	ldsh r0, [r1, r2]
	cmp r0, #0x63
	ble _0805CBB8
	ldr r4, [r7, #0x00]
	adds r0, r4, #0x0
	adds r0, #0xEE
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0805CBB8
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r3, _0805CBDC @ =0x00000002
	ldr r2, _0805CBD8 @ =0x00000000
	orrs r1, r3
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
_0805CBB8:
	mov r3, r12
	ldrh r0, [r3, #0x1C]
	adds r0, #0x01
_0805CBBE:
	strh r0, [r3, #0x1C]
_0805CBC0:
	mov r1, r12
	ldr r0, [r1, #0x0C]
	ldr r1, [r1, #0x10]
	subs r0, r0, r1
	asrs r0, r0, #0x02
	adds r1, r1, r0
	mov r2, r12
	str r1, [r2, #0x10]
_0805CBD0:
	movs r0, #0x01
_0805CBD2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_0805CBD8: .4byte 0x00000000
_0805CBDC: .4byte 0x00000002
.syntax divided
