@ Generated with Luvdis v0.8.0
.syntax unified
.text
@ Begin embedded Luvdis macros
	.macro arm_func_start name
	.align 2, 0
	.global \name
	.arm
	.type \name, %function
	.endm

	.macro arm_func_end name
	.size \name, .-\name
	.endm

	.macro thumb_func_start name
	.align 2, 0
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro non_word_aligned_thumb_func_start name
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro thumb_func_end name
	.size \name, .-\name
	.endm
@ End embedded Luvdis macros

	thumb_func_start func_08117E44
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
	thumb_func_start func_08117F5C
func_08117F5C: @ 08117F5C
	push {r4, r5, lr}
	adds r5, r2, #0x0
	ldr r3, _08117F8C @ =0x02038628
	ldr r2, _08117F90 @ =0x02038634
	str r1, [r2, #0x00]
	ldr r2, _08117F94 @ =0x0203862C
	ldrb r1, [r0, #0x00]
	str r1, [r2, #0x00]
	adds r0, #0x01
	str r0, [r3, #0x00]
	ldr r1, _08117F98 @ =0x02038630
	movs r0, #0x08
	str r0, [r1, #0x00]
	movs r4, #0x1F
_08117F78:
	adds r0, r5, #0x0
	bl func_08117E44
	adds r5, #0x10
	subs r4, #0x01
	cmp r4, #0x00
	bge _08117F78
	pop {r4, r5}
	pop {r0}
	bx r0
_08117F8C: .4byte 0x02038628
_08117F90: .4byte 0x02038634
_08117F94: .4byte 0x0203862C
_08117F98: .4byte 0x02038630
	.byte 0x70, 0xB5, 0x0D, 0x4C, 0x25, 0x68, 0x0D, 0x4E, 0x07, 0x2D, 0x0C, 0xDC, 0x30, 0x68, 0x00, 0x02
	.byte 0x30, 0x60, 0x0B, 0x4B, 0x19, 0x68, 0x0A, 0x78, 0x10, 0x43, 0x30, 0x60, 0x01, 0x31, 0x19, 0x60
	.byte 0x28, 0x1C, 0x08, 0x30, 0x20, 0x60, 0x21, 0x68, 0x08, 0x39, 0x30, 0x68, 0x08, 0x41, 0xFF, 0x21
	.byte 0x08, 0x40, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x30, 0x86, 0x03, 0x02, 0x2C, 0x86, 0x03, 0x02
	.byte 0x28, 0x86, 0x03, 0x02
	thumb_func_start func_08117FE0
func_08117FE0: @ 08117FE0
	swi #14
	bx lr
	thumb_func_start func_08117FE4
func_08117FE4: @ 08117FE4
	swi #12
	bx lr
	thumb_func_start func_08117FE8
func_08117FE8: @ 08117FE8
	swi #11
	bx lr
	.byte 0x01, 0xDF, 0x70, 0x47
	.global _08117FF0
_08117FF0:
	.byte 0x03, 0x4B, 0x00, 0x22, 0x1A, 0x70, 0x03, 0x49, 0x8D, 0x46, 0x01, 0xDF, 0x00, 0xDF, 0x00, 0x00
	.byte 0x08, 0x02, 0x00, 0x04, 0x00, 0x7F, 0x00, 0x03
	thumb_func_start func_08118008
func_08118008: @ 08118008
	swi #8
	bx lr
	.byte 0x00, 0x22, 0x05, 0xDF, 0x70, 0x47, 0x00, 0x00
