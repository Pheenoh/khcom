.syntax unified
	.align 2, 0
	.global func_08117E44
	.thumb
	.thumb_func
	.type func_08117E44, %function
func_08117E44: @ 08117E44
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	ldr r4, _08117E98 @ =0x02038630
	ldr r5, [r4, #0x00]
	ldr r7, _08117E9C @ =0x0203862C
	cmp r5, #0x01
	bge _08117E7A
	ldr r2, [r7, #0x00]
	lsls r2, r2, #0x08
	str r2, [r7, #0x00]
	ldr r3, _08117EA0 @ =0x02038628
	ldr r1, [r3, #0x00]
	ldrb r0, [r1, #0x00]
	orrs r0, r2
	str r0, [r7, #0x00]
	adds r1, #0x01
	str r1, [r3, #0x00]
	lsls r0, r0, #0x08
	str r0, [r7, #0x00]
	ldrb r2, [r1, #0x00]
	orrs r0, r2
	str r0, [r7, #0x00]
	adds r1, #0x01
	str r1, [r3, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x10
	str r0, [r4, #0x00]
_08117E7A:
	ldr r5, [r4, #0x00]
	subs r1, r5, #0x1
	str r1, [r4, #0x00]
	ldr r2, [r7, #0x00]
	adds r0, r2, #0x0
	asrs r0, r1
	movs r3, #0x01
	mov r12, r3
	ands r0, r3
	cmp r0, #0x00
	beq _08117EA4
	adds r0, r6, #0x0
	bl _08117A4C
	b _08117F54
_08117E98: .4byte 0x02038630
_08117E9C: .4byte 0x0203862C
_08117EA0: .4byte 0x02038628
_08117EA4:
	cmp r1, #0x01
	bge _08117ECE
	lsls r2, r2, #0x08
	str r2, [r7, #0x00]
	ldr r3, _08117EE8 @ =0x02038628
	ldr r1, [r3, #0x00]
	ldrb r0, [r1, #0x00]
	orrs r0, r2
	str r0, [r7, #0x00]
	adds r1, #0x01
	str r1, [r3, #0x00]
	lsls r0, r0, #0x08
	str r0, [r7, #0x00]
	ldrb r2, [r1, #0x00]
	orrs r0, r2
	str r0, [r7, #0x00]
	adds r1, #0x01
	str r1, [r3, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x0F
	str r0, [r4, #0x00]
_08117ECE:
	ldr r1, [r4, #0x00]
	subs r1, #0x01
	str r1, [r4, #0x00]
	ldr r0, [r7, #0x00]
	asrs r0, r1
	mov r1, r12
	ands r0, r1
	cmp r0, #0x00
	beq _08117EEC
	adds r0, r6, #0x0
	bl _08117674
	b _08117EF2
_08117EE8: .4byte 0x02038628
_08117EEC:
	adds r0, r6, #0x0
	bl _08117284
_08117EF2:
	ldr r4, _08117F40 @ =0x02038630
	ldr r5, [r4, #0x00]
	ldr r7, _08117F44 @ =0x0203862C
	cmp r5, #0x01
	bge _08117F24
	ldr r2, [r7, #0x00]
	lsls r2, r2, #0x08
	str r2, [r7, #0x00]
	ldr r3, _08117F48 @ =0x02038628
	ldr r1, [r3, #0x00]
	ldrb r0, [r1, #0x00]
	orrs r0, r2
	str r0, [r7, #0x00]
	adds r1, #0x01
	str r1, [r3, #0x00]
	lsls r0, r0, #0x08
	str r0, [r7, #0x00]
	ldrb r2, [r1, #0x00]
	orrs r0, r2
	str r0, [r7, #0x00]
	adds r1, #0x01
	str r1, [r3, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x10
	str r0, [r4, #0x00]
_08117F24:
	ldr r0, [r4, #0x00]
	subs r0, #0x01
	str r0, [r4, #0x00]
	ldr r1, [r7, #0x00]
	asrs r1, r0
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _08117F4C
	adds r0, r6, #0x0
	adds r0, #0x08
	bl _08117674
	b _08117F54
_08117F40: .4byte 0x02038630
_08117F44: .4byte 0x0203862C
_08117F48: .4byte 0x02038628
_08117F4C:
	adds r0, r6, #0x0
	adds r0, #0x08
	bl _08117284
_08117F54:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
