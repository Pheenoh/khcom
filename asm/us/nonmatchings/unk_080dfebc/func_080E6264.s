.syntax unified
	.align 2, 0
	.global func_080E6264
	.thumb
	.thumb_func
	.type func_080E6264, %function
func_080E6264: @ 080E6264
	push {r4, r5, r6, r7, lr}
	add sp, #-0x020
	ldr r7, _080E6290 @ =0x0203C7AC
	ldr r0, [r7, #0x00]
	ldrb r0, [r0, #0x0D]
	lsls r0, r0, #0x03
	ldr r1, _080E6294 @ =0x0984D134
	adds r4, r0, r1
	ldr r5, _080E6298 @ =0x02039BA0
	ldr r2, [r5, #0x00]
	ldr r0, [r2, #0x70]
	ldr r1, _080E629C @ =0xFFFEFFFF
	ands r0, r1
	str r0, [r2, #0x70]
	ldr r1, _080E62A0 @ =0x02034F42
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080E62A4
	subs r0, #0x01
	strb r0, [r1, #0x00]
	b _080E637C
	.byte 0x00, 0x00
_080E6290: .4byte 0x0203C7AC
_080E6294: .4byte 0x0984D134
_080E6298: .4byte 0x02039BA0
_080E629C: .4byte 0xFFFEFFFF
_080E62A0: .4byte 0x02034F42
_080E62A4:
	ldr r6, _080E62FC @ =0x0203C590
	ldrb r0, [r6, #0x06]
	bl func_080DEE18
	adds r1, r0, #0x0
	ldr r2, _080E6300 @ =0x02034F40
	ldrb r0, [r2, #0x00]
	ldrb r4, [r4, #0x01]
	cmp r0, r4
	bcs _080E637C
	ldrb r0, [r1, #0x0B]
	ldrb r1, [r2, #0x00]
	subs r0, r0, r1
	cmp r0, #0x00
	ble _080E637C
	ldr r0, [r5, #0x00]
	ldr r0, [r0, #0x70]
	ldr r1, _080E6304 @ =0x00040280
	ands r0, r1
	cmp r0, #0x00
	bne _080E637C
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080E6308 @ =0x00002710
	bl __umodsi3
	lsls r0, r0, #0x10
	ldr r1, _080E630C @ =0x1F3F0000
	cmp r0, r1
	bls _080E637C
	ldr r0, [r7, #0x00]
	ldrb r0, [r0, #0x0D]
	cmp r0, #0x14
	beq _080E6314
	cmp r0, #0x15
	beq _080E6320
	ldrb r0, [r6, #0x04]
	cmp r0, #0x02
	bne _080E632C
	ldr r0, _080E6310 @ =0x09EF83F8
	ldr r4, [r0, #0x10]
	b _080E6350
_080E62FC: .4byte 0x0203C590
_080E6300: .4byte 0x02034F40
_080E6304: .4byte 0x00040280
_080E6308: .4byte 0x00002710
_080E630C: .4byte 0x1F3F0000
_080E6310: .4byte 0x09EF83F8
_080E6314:
	ldr r0, _080E631C @ =0x09EF83F8
	ldr r4, [r0, #0x14]
	b _080E6350
	.byte 0x00, 0x00
_080E631C: .4byte 0x09EF83F8
_080E6320:
	ldr r0, _080E6328 @ =0x09EF83F8
	ldr r4, [r0, #0x18]
	b _080E6350
	.byte 0x00, 0x00
_080E6328: .4byte 0x09EF83F8
_080E632C:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _080E634C
	ldr r0, _080E6348 @ =0x09EF83F8
	ldr r4, [r0, #0x00]
	b _080E6350
	.byte 0x00, 0x00
_080E6348: .4byte 0x09EF83F8
_080E634C:
	ldr r0, _080E6384 @ =0x09EF83F8
	ldr r4, [r0, #0x04]
_080E6350:
	ldr r0, _080E6388 @ =0x02034F41
	ldrb r0, [r0, #0x00]
	ldrh r1, [r4, #0x08]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x01
	cmp r0, r1
	bgt _080E637C
	ldr r1, _080E638C @ =0x02034F42
	movs r0, #0x1E
	strb r0, [r1, #0x00]
	mov r0, sp
	adds r1, r4, #0x0
	bl func_080E5B90
	ldr r0, _080E6390 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0xB4
	ldr r1, [r4, #0x10]
	mov r2, sp
	bl func_08000E14
_080E637C:
	add sp, #0x020
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E6384: .4byte 0x09EF83F8
_080E6388: .4byte 0x02034F41
_080E638C: .4byte 0x02034F42
_080E6390: .4byte 0x02039BA0
.syntax divided
